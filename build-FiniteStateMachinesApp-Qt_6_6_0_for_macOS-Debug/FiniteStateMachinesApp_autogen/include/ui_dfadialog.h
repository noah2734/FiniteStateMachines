/********************************************************************************
** Form generated from reading UI file 'dfadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DFADIALOG_H
#define UI_DFADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DFADialog
{
public:
    QLineEdit *stateNameLine;
    QCheckBox *StartCheckBox;
    QCheckBox *AcceptCheckBox;
    QPushButton *EnterStateBtn;
    QFrame *frame;
    QLabel *stateCounterLbl;
    QLabel *statesLbl;
    QLineEdit *symbolLine;
    QPushButton *EnterSymBtn;
    QFrame *frame_2;
    QLabel *symLbl;
    QLabel *numSymLbl;
    QFrame *frame_3;
    QLabel *StateLbl1;
    QLabel *currStateLbl;
    QLabel *SymbolLbl;
    QLabel *OnSymbolLbl;
    QLabel *goesToLbl;
    QLineEdit *gotoLine;
    QPushButton *EnterTransBtn;
    QLabel *numTransLbl;
    QLabel *numForTransLbl;
    QLabel *startStateErrorLbl;
    QLabel *transErrorLbl;
    QTextEdit *textEdit;

    void setupUi(QDialog *DFADialog)
    {
        if (DFADialog->objectName().isEmpty())
            DFADialog->setObjectName("DFADialog");
        DFADialog->resize(684, 300);
        stateNameLine = new QLineEdit(DFADialog);
        stateNameLine->setObjectName("stateNameLine");
        stateNameLine->setGeometry(QRect(90, 20, 113, 31));
        StartCheckBox = new QCheckBox(DFADialog);
        StartCheckBox->setObjectName("StartCheckBox");
        StartCheckBox->setGeometry(QRect(10, 60, 85, 20));
        AcceptCheckBox = new QCheckBox(DFADialog);
        AcceptCheckBox->setObjectName("AcceptCheckBox");
        AcceptCheckBox->setGeometry(QRect(110, 60, 111, 20));
        EnterStateBtn = new QPushButton(DFADialog);
        EnterStateBtn->setObjectName("EnterStateBtn");
        EnterStateBtn->setGeometry(QRect(20, 20, 61, 32));
        frame = new QFrame(DFADialog);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(210, 20, 111, 21));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        stateCounterLbl = new QLabel(frame);
        stateCounterLbl->setObjectName("stateCounterLbl");
        stateCounterLbl->setGeometry(QRect(80, 0, 31, 16));
        statesLbl = new QLabel(frame);
        statesLbl->setObjectName("statesLbl");
        statesLbl->setGeometry(QRect(0, 0, 74, 16));
        symbolLine = new QLineEdit(DFADialog);
        symbolLine->setObjectName("symbolLine");
        symbolLine->setGeometry(QRect(90, 110, 61, 31));
        EnterSymBtn = new QPushButton(DFADialog);
        EnterSymBtn->setObjectName("EnterSymBtn");
        EnterSymBtn->setGeometry(QRect(20, 110, 61, 32));
        frame_2 = new QFrame(DFADialog);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(160, 120, 131, 21));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        symLbl = new QLabel(frame_2);
        symLbl->setObjectName("symLbl");
        symLbl->setGeometry(QRect(10, 0, 91, 16));
        numSymLbl = new QLabel(frame_2);
        numSymLbl->setObjectName("numSymLbl");
        numSymLbl->setGeometry(QRect(100, 0, 31, 16));
        frame_3 = new QFrame(DFADialog);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 170, 321, 101));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        StateLbl1 = new QLabel(frame_3);
        StateLbl1->setObjectName("StateLbl1");
        StateLbl1->setGeometry(QRect(10, 10, 41, 16));
        currStateLbl = new QLabel(frame_3);
        currStateLbl->setObjectName("currStateLbl");
        currStateLbl->setGeometry(QRect(50, 10, 101, 16));
        SymbolLbl = new QLabel(frame_3);
        SymbolLbl->setObjectName("SymbolLbl");
        SymbolLbl->setGeometry(QRect(10, 40, 71, 16));
        OnSymbolLbl = new QLabel(frame_3);
        OnSymbolLbl->setObjectName("OnSymbolLbl");
        OnSymbolLbl->setGeometry(QRect(90, 40, 41, 16));
        goesToLbl = new QLabel(frame_3);
        goesToLbl->setObjectName("goesToLbl");
        goesToLbl->setGeometry(QRect(10, 70, 58, 16));
        gotoLine = new QLineEdit(frame_3);
        gotoLine->setObjectName("gotoLine");
        gotoLine->setGeometry(QRect(70, 60, 113, 31));
        EnterTransBtn = new QPushButton(frame_3);
        EnterTransBtn->setObjectName("EnterTransBtn");
        EnterTransBtn->setGeometry(QRect(200, 60, 61, 32));
        numTransLbl = new QLabel(frame_3);
        numTransLbl->setObjectName("numTransLbl");
        numTransLbl->setGeometry(QRect(150, 10, 111, 16));
        numForTransLbl = new QLabel(frame_3);
        numForTransLbl->setObjectName("numForTransLbl");
        numForTransLbl->setGeometry(QRect(260, 10, 31, 16));
        startStateErrorLbl = new QLabel(DFADialog);
        startStateErrorLbl->setObjectName("startStateErrorLbl");
        startStateErrorLbl->setGeometry(QRect(30, 80, 291, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        startStateErrorLbl->setFont(font);
        transErrorLbl = new QLabel(DFADialog);
        transErrorLbl->setObjectName("transErrorLbl");
        transErrorLbl->setGeometry(QRect(27, 270, 331, 20));
        textEdit = new QTextEdit(DFADialog);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(373, 63, 221, 151));

        retranslateUi(DFADialog);

        QMetaObject::connectSlotsByName(DFADialog);
    } // setupUi

    void retranslateUi(QDialog *DFADialog)
    {
        DFADialog->setWindowTitle(QCoreApplication::translate("DFADialog", "Dialog", nullptr));
        stateNameLine->setText(QString());
        StartCheckBox->setText(QCoreApplication::translate("DFADialog", "Start State?", nullptr));
        AcceptCheckBox->setText(QCoreApplication::translate("DFADialog", "Accept State", nullptr));
        EnterStateBtn->setText(QCoreApplication::translate("DFADialog", "Enter", nullptr));
        stateCounterLbl->setText(QCoreApplication::translate("DFADialog", "0", nullptr));
        statesLbl->setText(QCoreApplication::translate("DFADialog", "Total States:", nullptr));
        symbolLine->setText(QString());
        EnterSymBtn->setText(QCoreApplication::translate("DFADialog", "Enter", nullptr));
        symLbl->setText(QCoreApplication::translate("DFADialog", "Total symbols:", nullptr));
        numSymLbl->setText(QCoreApplication::translate("DFADialog", "0", nullptr));
        StateLbl1->setText(QCoreApplication::translate("DFADialog", "State: ", nullptr));
        currStateLbl->setText(QString());
        SymbolLbl->setText(QCoreApplication::translate("DFADialog", "On Symbol: ", nullptr));
        OnSymbolLbl->setText(QString());
        goesToLbl->setText(QCoreApplication::translate("DFADialog", "Goes To:", nullptr));
        gotoLine->setText(QString());
        EnterTransBtn->setText(QCoreApplication::translate("DFADialog", "Enter", nullptr));
        numTransLbl->setText(QCoreApplication::translate("DFADialog", "Total Transitions: ", nullptr));
        numForTransLbl->setText(QCoreApplication::translate("DFADialog", "0", nullptr));
        startStateErrorLbl->setText(QString());
        transErrorLbl->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DFADialog: public Ui_DFADialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DFADIALOG_H
