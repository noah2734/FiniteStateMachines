#include "dfadialog.h"
#include "ui_dfadialog.h"

DFADialog::DFADialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DFADialog)
{
    ui->setupUi(this);
    //connect
}

DFADialog::~DFADialog()
{
    delete ui;
}
