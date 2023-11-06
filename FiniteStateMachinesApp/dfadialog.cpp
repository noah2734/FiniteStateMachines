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


//std::string currStateName = startname;

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

}

DFADialog::~DFADialog()
{
    delete ui;
}
std::string firstStateName; //use as starting point when getting transition input
//for states
void DFADialog::onStateEnter() {
    if (start && startExists) {
        ui->startStateErrorLbl->setStyleSheet("color: red;");
        ui->startStateErrorLbl->setText("You already have a start state.");
    } else {
        std::string name = ui->stateNameLine->text().toStdString();
        if (start) {
            startExists = true;
            //startName = name;
            dfa.addState(name, start, acc);
            connectedStates.push_back(dfa.getState(name).name);
            firstStateName = connectedStates[0];
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
int symbolIndex = 0;

std::string toStateName;
std::string currStateName = firstStateName;
std::string currSymbol = firstSymbol;

bool inConnectedStates(std::string stateName) {
    for (auto& st : connectedStates) {
        if (stateName == st) {
            return true;
        }
    }
    return false;
}

std::string trueStateName;
int numTransCounter = 0;
int maxTrans;

void DFADialog::onTransEnter() {
    maxTrans = dfa.getNumStates() * dfa.getNumSymbols();
    graph.addVertex(currStateName);
    toStateName = ui->gotoLine->text().toStdString();
    graph.addEdge(currStateName, toStateName, currSymbol);
    dfa.addTransition(currStateName, currSymbol, toStateName);
    numTransCounter++;
    if (numTransCounter == maxTrans) {
        ui->textEdit->setText(QString::fromStdString(graph.toString()));
        return;
    }
    ui->numForTransLbl->setText(QString::number(numTransCounter));

    symbolIndex++;
    if (symbolIndex == symbolCounter) {
        symbolIndex = 0;
        connectedStatesCounter++;
    }
    for (auto& st : connectedStates) {
        qDebug() << st << "\n" << "--------" << "\n";
    }
    ui->currStateLbl->setText(QString::fromStdString(connectedStates[connectedStatesCounter]));
    currStateName = connectedStates[connectedStatesCounter];
    trueStateName = dfa.getState(toStateName).name;
    if (!inConnectedStates(toStateName) && trueStateName != "") {
        connectedStates.push_back(dfa.getState(toStateName).name);
    }

    if (trueStateName == "") {
        ui->transErrorLbl->setStyleSheet("color: red");
        ui->transErrorLbl->setText(QString::fromStdString(toStateName) + " does not exist!");
        return;
    }
    ui->transErrorLbl->setText("");
    currSymbol = dfa.getSymbol(symbolIndex);
    ui->OnSymbolLbl->setText(QString::fromStdString(currSymbol));
}

void DFADialog::onTransEnter() {

}


