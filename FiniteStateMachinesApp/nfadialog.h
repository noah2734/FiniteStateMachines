#ifndef NFADIALOG_H
#define NFADIALOG_H

#include <QDialog>
#include "machine.h"

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
    void onTransSubmit();
    
    void displayGraph(Graph *graph);
    void onBuildEnter();
    void onTestEnter();

    void compute(std::string input);
};

#endif // NFADIALOG_H
