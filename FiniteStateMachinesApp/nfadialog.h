#ifndef NFADIALOG_H
#define NFADIALOG_H

#include <QDialog>

namespace Ui {
class NFADialog;
}

class NFADialog : public QDialog
{
    Q_OBJECT

public:
    explicit NFADialog(QWidget *parent = nullptr);
    ~NFADialog();

private:
    Ui::NFADialog *ui;
private slots:
    void onStateEnter();
    void updateStart(int);
    void updateAccept(int);
    void onSymbEnter();
    void onTransEnter();
    void onBuildEnter();
    void onTestEnter();
};

#endif // NFADIALOG_H
