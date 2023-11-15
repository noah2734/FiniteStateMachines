#include "nfadialog.h"
#include "ui_nfadialog.h"
#include "machine.h"

#include <vector>
#include <string>

NFADialog::NFADialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NFADialog)
{
    ui->setupUi(this);

    ui->stateNameLine->setPlaceholderText("State Name");

    connect(ui->EnterStateBtn, &QPushButton::clicked, this, &NFADialog::onStateEnter);
    connect(ui->StartCheckBox, &QCheckBox::stateChanged, this, &NFADialog::updateStart);
    connect(ui->AcceptCheckBox, &QCheckBox::stateChanged, this, &NFADialog::updateAccept);

    ui->symbolLine->setPlaceholderText("Symbol");

    connect(ui->EnterSymBtn, &QPushButton::clicked, this, &NFADialog::onSymbEnter);

    connect(ui->EnterTransBtn, &QPushButton::clicked, this, &NFADialog::onTransEnter);

    connect(ui->buildBtn, &QPushButton::clicked, this, &NFADialog::onBuildEnter);

    connect(ui->testBtn, &QPushButton::clicked, this, &NFADialog::onTestEnter);

    ui->transErrorLbl->setStyleSheet("color: red");

    ui->startStateErrorLbl->setStyleSheet("color: red;");

    ui->buildErrLbl->setStyleSheet("color: red;");

}

NFADialog::~NFADialog()
{
    delete ui;
}

NFA nfa;
std::vector<std::string> connectedStates;

bool start = false;
bool accept = false;
bool startExists = false;
std::string stateName;

void NFADialog::onStateEnter()
{
    if (start && startExists) {
        ui->startStateErrorLbl->setText("You already have a start state.");
    } else {
        std::string stateName = ui->stateNameLine->text().toStdString();

        if (start) {
            startExists = true;
            nfa.setStartState(stateName);
            nfa.connectedStates.push_back(stateName);
        }
        nfa.addState(stateName, start, accept);
    }
}

void NFADialog::updateStart(int state) {
    start = (state == Qt::Checked);
}

void NFADialog::updateAccept()
{
    std::string stateName = ui->stateNameLine->text().toStdString();
    if (stateName == "")
    {
        ui->stateNameLine->setPlaceholderText("State Name");
        return;
    }
    if (machine->getState(stateName) == nullptr)
    {
        ui->stateNameLine->setPlaceholderText("State does not exist");
        return;
    }
    machine->setAcceptState(stateName);
}

void NFADialog::onSymbEnter()
{
    std::string symbol = ui->symbolLine->text().toStdString();
    if (symbol == "")
    {
        ui->symbolLine->setPlaceholderText("Symbol");
        return;
    }
    if (machine->getSymbol(symbol) != nullptr)
    {
        ui->symbolLine->setPlaceholderText("Symbol already exists");
        return;
    }
    machine->addSymbol(symbol);
    ui->symbolLine->clear();
}