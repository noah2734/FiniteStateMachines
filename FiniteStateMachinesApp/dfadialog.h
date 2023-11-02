#ifndef DFADIALOG_H
#define DFADIALOG_H

#include <QDialog>

namespace Ui {
class DFADialog;
}

class DFADialog : public QDialog
{
    Q_OBJECT

public:
    explicit DFADialog(QWidget *parent = nullptr);
    ~DFADialog();

private:
    Ui::DFADialog *ui;
};

#endif // DFADIALOG_H
