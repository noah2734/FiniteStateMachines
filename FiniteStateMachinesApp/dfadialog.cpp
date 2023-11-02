#include "dfadialog.h"
#include "ui_dfadialog.h"


DFADialog::DFADialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DFADialog)
{
    ui->setupUi(this);
    connect(ui->EnterStateBtn, SIGNAL(clicked()), this, SLOT(onStateEnter()));
}

DFADialog::~DFADialog()
{
    delete ui;
}

void DFADialog::onStateEnter() {

}
