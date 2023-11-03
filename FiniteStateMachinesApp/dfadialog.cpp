#include "dfadialog.h"
#include "ui_dfadialog.h"
#include "machine.h"

bool start = false;
bool acc = false;
bool startExists = false;
int stateCounter = 0;
int symbolCounter = 0;
int start_id;

DFA dfa;

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
    ui->symbolLine->setPlaceholderText("symbol");
    //for transitions
    connect(ui->EnterTransBtn, &QPushButton::clicked, this, &DFADialog::onTransEnter);

}

DFADialog::~DFADialog()
{
    delete ui;
}
//for states
void DFADialog::onStateEnter() {
    if (start && startExists) {
        ui->startStateErrorLbl->setStyleSheet("color: red;");
        ui->startStateErrorLbl->setText("You already have a start state.");
    } else {
        std::string name = ui->stateNameLine->text().toStdString();
        if (start) {
            startExists = true;
            ui->currStateLbl->setText(QString::fromStdString(name));
            start_id = stateCounter + 1;
        }
        ui->startStateErrorLbl->setText("");
        stateCounter++;
        ui->stateCounterLbl->setText(QString::number(stateCounter));
        dfa.addState(name, start, acc);
        qDebug() << "added state with name " << name << " start = " << start << " accept = " << acc;
    }
}

void DFADialog::updateStart(int state) {
    start = (state == Qt::Checked);
}

void DFADialog::updateAccept(int state) {
    acc = (state == Qt::Checked);
}
//for symbols
void DFADialog::onSymbEnter() {
    if (ui->symbolLine->text().isEmpty()) {
        qDebug() << "no entry";
        return;
    }
    if(dfa.emptySymbols()) {
        ui->OnSymbolLbl->setText(ui->symbolLine->text());
    }
    ui->numSymLbl->setText(QString::number(++symbolCounter));
    dfa.addSymbol(ui->symbolLine->text().toStdString());

}



void DFADialog::onTransEnter() {
    std::string from = ui->currStateLbl->text().toStdString();
    std::string on = ui->OnSymbolLbl->text().toStdString();
    std::string to = ui->gotoLine->text().toStdString();



}


