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
#include <QtWidgets/QGraphicsView>
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
    QLineEdit *symbolLine;
    QPushButton *EnterSymBtn;
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
    QPushButton *buildBtn;
    QLabel *buildErrBtn;
    QGraphicsView *machineView;
    QLineEdit *testLine;
    QPushButton *testBtn;
    QLabel *numSymLbl;
    QLabel *symLbl;
    QLabel *stateCounterLbl;
    QLabel *statesLbl;

    void setupUi(QDialog *DFADialog)
    {
        if (DFADialog->objectName().isEmpty())
            DFADialog->setObjectName("DFADialog");
        DFADialog->resize(640, 700);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(152, 156, 155, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(228, 234, 232, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(190, 195, 193, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(76, 78, 77, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(101, 104, 103, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(203, 205, 205, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush10(QColor(76, 78, 77, 127));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        DFADialog->setPalette(palette);
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
        symbolLine = new QLineEdit(DFADialog);
        symbolLine->setObjectName("symbolLine");
        symbolLine->setGeometry(QRect(90, 110, 61, 31));
        EnterSymBtn = new QPushButton(DFADialog);
        EnterSymBtn->setObjectName("EnterSymBtn");
        EnterSymBtn->setGeometry(QRect(20, 110, 61, 32));
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
        buildBtn = new QPushButton(DFADialog);
        buildBtn->setObjectName("buildBtn");
        buildBtn->setGeometry(QRect(440, 240, 75, 24));
        buildErrBtn = new QLabel(DFADialog);
        buildErrBtn->setObjectName("buildErrBtn");
        buildErrBtn->setGeometry(QRect(360, 270, 261, 20));
        machineView = new QGraphicsView(DFADialog);
        machineView->setObjectName("machineView");
        machineView->setGeometry(QRect(35, 340, 500, 350));
        testLine = new QLineEdit(DFADialog);
        testLine->setObjectName("testLine");
        testLine->setGeometry(QRect(40, 301, 113, 31));
        testBtn = new QPushButton(DFADialog);
        testBtn->setObjectName("testBtn");
        testBtn->setGeometry(QRect(170, 300, 75, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush11(QColor(125, 126, 129, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush11);
        QBrush brush12(QColor(187, 189, 194, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush12);
        QBrush brush13(QColor(156, 157, 161, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        QBrush brush14(QColor(62, 63, 65, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush14);
        QBrush brush15(QColor(83, 84, 86, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush16(QColor(190, 190, 192, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush16);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush17(QColor(62, 63, 65, 127));
        brush17.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush17);
#endif
        testBtn->setPalette(palette1);
        testBtn->setAutoDefault(true);
        testBtn->setFlat(false);
        numSymLbl = new QLabel(DFADialog);
        numSymLbl->setObjectName("numSymLbl");
        numSymLbl->setGeometry(QRect(250, 120, 31, 16));
        symLbl = new QLabel(DFADialog);
        symLbl->setObjectName("symLbl");
        symLbl->setGeometry(QRect(160, 120, 91, 16));
        stateCounterLbl = new QLabel(DFADialog);
        stateCounterLbl->setObjectName("stateCounterLbl");
        stateCounterLbl->setGeometry(QRect(300, 30, 31, 16));
        statesLbl = new QLabel(DFADialog);
        statesLbl->setObjectName("statesLbl");
        statesLbl->setGeometry(QRect(220, 30, 74, 16));

        retranslateUi(DFADialog);

        testBtn->setDefault(false);


        QMetaObject::connectSlotsByName(DFADialog);
    } // setupUi

    void retranslateUi(QDialog *DFADialog)
    {
        DFADialog->setWindowTitle(QCoreApplication::translate("DFADialog", "Dialog", nullptr));
        stateNameLine->setText(QString());
        StartCheckBox->setText(QCoreApplication::translate("DFADialog", "Start State?", nullptr));
        AcceptCheckBox->setText(QCoreApplication::translate("DFADialog", "Accept State", nullptr));
        EnterStateBtn->setText(QCoreApplication::translate("DFADialog", "Enter", nullptr));
        symbolLine->setText(QString());
        EnterSymBtn->setText(QCoreApplication::translate("DFADialog", "Enter", nullptr));
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
        buildBtn->setText(QCoreApplication::translate("DFADialog", "Build", nullptr));
        buildErrBtn->setText(QString());
        testBtn->setText(QCoreApplication::translate("DFADialog", "Test", nullptr));
        numSymLbl->setText(QCoreApplication::translate("DFADialog", "0", nullptr));
        symLbl->setText(QCoreApplication::translate("DFADialog", "Total symbols:", nullptr));
        stateCounterLbl->setText(QCoreApplication::translate("DFADialog", "0", nullptr));
        statesLbl->setText(QCoreApplication::translate("DFADialog", "Total States:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DFADialog: public Ui_DFADialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DFADIALOG_H
