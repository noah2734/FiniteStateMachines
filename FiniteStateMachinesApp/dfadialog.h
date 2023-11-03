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
private slots:
    //for states
    void onStateEnter();
    void updateStart(int);
    void updateAccept(int);
    //for symbols
    void onSymbEnter();
    //for transitions
    void onTransEnter();
};

#endif // DFADIALOG_H
