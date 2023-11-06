#include "dfadialog.h"
#include "ui_dfadialog.h"
#include "machine.h"


#include <vector>
#include <string>

bool start = false;
bool acc = false;
bool startExists = false;
int stateCounter = 0;
int symbolCounter = 0;
int start_id;

DFA dfa;
Graph graph;

std::vector<std::string> connectedStates; // see onStateEnter and onTransEnter

DFADialog::DFADialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DFADialog)
{
    ui->setupUi(this);
    //for state data
    connect(ui->EnterStateBtn, &QPushButton::clicked, this, &DFADialog::onStateEnter);
    connect(ui->StartCheckBox, &QCheckBox::stateChanged, this, &DFADialog::updateStart);
    connect(ui->AcceptCheckBox, &QCheckBox::stateChanged, this, &DFADialog::updateAccept);
    ui->stateNameLine->setPlaceholderText("State Name");
    //for symbols
    connect(ui->EnterSymBtn, &QPushButton::clicked, this, &DFADialog::onSymbEnter);
    ui->symbolLine->setPlaceholderText("Symbol");
    //for transitions
    connect(ui->EnterTransBtn, &QPushButton::clicked, this, &DFADialog::onTransEnter);
    ui->gotoLine->setPlaceholderText("State Name");

    ui->transErrorLbl->setStyleSheet("color: red");

}

DFADialog::~DFADialog()
{
    delete ui;
}
std::string startStateName; //use as starting point when getting transition input
//for states
void DFADialog::onStateEnter() {
    if (start && startExists) {
        ui->startStateErrorLbl->setStyleSheet("color: red;");
        ui->startStateErrorLbl->setText("You already have a start state.");
    } else {
        std::string name = ui->stateNameLine->text().toStdString();
        if (start) {
            startExists = true;
            startStateName = name;
            dfa.addState(name, start, acc);
            connectedStates.push_back(dfa.getState(name).name);
            //firstStateName = connectedStates[0];
            stateCounter++;
            ui->stateCounterLbl->setText(QString::number(stateCounter));
            ui->currStateLbl->setText(QString::fromStdString(name));
            ui->stateNameLine->setText("");
            qDebug() << "added START state with name " << name << " ACCEPT = " << acc;
        } else {
            ui->startStateErrorLbl->setText("");
            stateCounter++;
            ui->stateCounterLbl->setText(QString::number(stateCounter));
            dfa.addState(name, start, acc);
            ui->stateNameLine->setText("");
            qDebug() << "added state with name " << name << " ACCEPT = " << acc;
        }
    }
}

void DFADialog::updateStart(int state) {
    start = (state == Qt::Checked);
}

void DFADialog::updateAccept(int state) {
    acc = (state == Qt::Checked);
}
//for symbols
std::string firstSymbol;
void DFADialog::onSymbEnter() {
    if (ui->symbolLine->text().isEmpty()) {
        qDebug() << "no entry";
        return;
    }
    if(dfa.emptySymbols()) {
        firstSymbol = ui->symbolLine->text().toStdString();
        ui->OnSymbolLbl->setText(ui->symbolLine->text());
    }
    ui->numSymLbl->setText(QString::number(++symbolCounter));
    dfa.addSymbol(ui->symbolLine->text().toStdString());
    ui->symbolLine->setText("");

}

int connectedStatesCounter = 0;

bool inConnectedStates(std::string stateName) {
    for (auto& st : connectedStates) {
        if (stateName == st) {
            return true;
        }
    }
    return false;
}

std::string fromStateName;
std::string toStateName;
std::string currSymbol;
int numTransCounter = 0;
int symbolIndex = 0;
int stateIndex = 0; //use for connected states
bool reachedMax = false;

void DFADialog::onTransEnter() {
    if (reachedMax) {
        ui->transErrorLbl->setText("You have entered every possible transition");
        return;
    }
    fromStateName = connectedStates[stateIndex];
    toStateName = ui->gotoLine->text().toStdString();
    currSymbol = dfa.getSymbol(symbolIndex);

    if (!inConnectedStates(toStateName) && dfa.stateExists(toStateName)) {
        connectedStates.push_back(dfa.getState(toStateName).name);
    } else if (!(dfa.stateExists(toStateName))) {
        ui->transErrorLbl->setText(QString::fromStdString(toStateName) + " does not exist!");
    }

    qDebug() << "From state: " << QString::fromStdString(fromStateName) << "\n";
    qDebug() << "On " << QString::fromStdString(currSymbol) << "\n";
    qDebug() << "To state: " << QString::fromStdString(toStateName) << "\n";
    qDebug() << "symbolIndex: " << QString::number(symbolIndex) << "\n";
    qDebug() << "stateIndex: " << QString::number(stateIndex) << "\n";

    //not sure if ill need a graph AND set of transitions, but whatever
    graph.addVertex(fromStateName);
    graph.addEdge(fromStateName, toStateName, currSymbol);
    dfa.addTransition(fromStateName, currSymbol, toStateName);
    ui->transErrorLbl->setText("");

    ui->numForTransLbl->setText(QString::number(++numTransCounter));

    symbolIndex++;

    //(numSymbols) transitions per state for DFA
    if (symbolIndex == dfa.getNumSymbols()) {
        symbolIndex = 0;
        if (stateIndex == connectedStates.size() - 1) {
            reachedMax = true;
            //print graph
            ui->textEdit->setText(QString::fromStdString(graph.toString()));
            return;
        }
        stateIndex++;
    }

    ui->currStateLbl->setText(QString::fromStdString(connectedStates[stateIndex]));
    ui->OnSymbolLbl->setText(QString::fromStdString(dfa.getSymbol(symbolIndex)));
}

