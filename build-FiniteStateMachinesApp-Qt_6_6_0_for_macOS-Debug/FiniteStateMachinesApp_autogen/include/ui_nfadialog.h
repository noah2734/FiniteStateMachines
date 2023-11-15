/********************************************************************************
** Form generated from reading UI file 'nfadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NFADIALOG_H
#define UI_NFADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NFADialog
{
public:
    QCheckBox *StartCheckBox;
    QCheckBox *AcceptCheckBox;
    QLabel *startStateErrorLbl;
    QLabel *transErrorLbl;
    QTextEdit *textEdit;
    QPushButton *buildBtn;
    QLabel *buildErrLbl;
    QGraphicsView *machineView;
    QLineEdit *testLine;
    QPushButton *testBtn;
    QLabel *numSymLbl;
    QLabel *symLbl;
    QLabel *stateCounterLbl;
    QLabel *statesLbl;
    QLabel *testInputLbl;
    QLabel *testResultLbl;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *EnterStateBtn;
    QLineEdit *stateNameLine;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *EnterSymBtn;
    QLineEdit *symbolLine;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *FromStateCbox;
    QLabel *goesToLbl;
    QComboBox *ToStateCbox;
    QLabel *enterSymbolsLbl;
    QLabel *enterStatesLbl;
    QLabel *enterTransLbl;
    QPushButton *submitTransBtn;
    QLabel *TotalTransLbl;
    QLabel *numTransLbl;

    void setupUi(QDialog *NFADialog)
    {
        if (NFADialog->objectName().isEmpty())
            NFADialog->setObjectName("NFADialog");
        NFADialog->resize(640, 700);
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
        NFADialog->setPalette(palette);
        StartCheckBox = new QCheckBox(NFADialog);
        StartCheckBox->setObjectName("StartCheckBox");
        StartCheckBox->setGeometry(QRect(10, 70, 85, 20));
        AcceptCheckBox = new QCheckBox(NFADialog);
        AcceptCheckBox->setObjectName("AcceptCheckBox");
        AcceptCheckBox->setGeometry(QRect(110, 70, 111, 20));
        startStateErrorLbl = new QLabel(NFADialog);
        startStateErrorLbl->setObjectName("startStateErrorLbl");
        startStateErrorLbl->setGeometry(QRect(10, 90, 291, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        startStateErrorLbl->setFont(font);
        transErrorLbl = new QLabel(NFADialog);
        transErrorLbl->setObjectName("transErrorLbl");
        transErrorLbl->setGeometry(QRect(10, 280, 331, 20));
        textEdit = new QTextEdit(NFADialog);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(380, 80, 221, 151));
        buildBtn = new QPushButton(NFADialog);
        buildBtn->setObjectName("buildBtn");
        buildBtn->setGeometry(QRect(460, 240, 75, 24));
        buildErrLbl = new QLabel(NFADialog);
        buildErrLbl->setObjectName("buildErrLbl");
        buildErrLbl->setGeometry(QRect(360, 270, 261, 20));
        machineView = new QGraphicsView(NFADialog);
        machineView->setObjectName("machineView");
        machineView->setGeometry(QRect(35, 340, 500, 350));
        testLine = new QLineEdit(NFADialog);
        testLine->setObjectName("testLine");
        testLine->setGeometry(QRect(40, 301, 113, 31));
        testBtn = new QPushButton(NFADialog);
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
        numSymLbl = new QLabel(NFADialog);
        numSymLbl->setObjectName("numSymLbl");
        numSymLbl->setGeometry(QRect(590, 30, 31, 16));
        symLbl = new QLabel(NFADialog);
        symLbl->setObjectName("symLbl");
        symLbl->setGeometry(QRect(480, 30, 91, 16));
        stateCounterLbl = new QLabel(NFADialog);
        stateCounterLbl->setObjectName("stateCounterLbl");
        stateCounterLbl->setGeometry(QRect(590, 10, 31, 16));
        statesLbl = new QLabel(NFADialog);
        statesLbl->setObjectName("statesLbl");
        statesLbl->setGeometry(QRect(480, 10, 74, 16));
        testInputLbl = new QLabel(NFADialog);
        testInputLbl->setObjectName("testInputLbl");
        testInputLbl->setGeometry(QRect(270, 310, 161, 16));
        testResultLbl = new QLabel(NFADialog);
        testResultLbl->setObjectName("testResultLbl");
        testResultLbl->setGeometry(QRect(450, 310, 81, 16));
        horizontalLayoutWidget = new QWidget(NFADialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 30, 201, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        EnterStateBtn = new QPushButton(horizontalLayoutWidget);
        EnterStateBtn->setObjectName("EnterStateBtn");

        horizontalLayout->addWidget(EnterStateBtn);

        stateNameLine = new QLineEdit(horizontalLayoutWidget);
        stateNameLine->setObjectName("stateNameLine");

        horizontalLayout->addWidget(stateNameLine);

        horizontalLayoutWidget_2 = new QWidget(NFADialog);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 140, 191, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        EnterSymBtn = new QPushButton(horizontalLayoutWidget_2);
        EnterSymBtn->setObjectName("EnterSymBtn");

        horizontalLayout_2->addWidget(EnterSymBtn);

        symbolLine = new QLineEdit(horizontalLayoutWidget_2);
        symbolLine->setObjectName("symbolLine");

        horizontalLayout_2->addWidget(symbolLine);

        horizontalLayoutWidget_3 = new QWidget(NFADialog);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 220, 276, 32));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        FromStateCbox = new QComboBox(horizontalLayoutWidget_3);
        FromStateCbox->setObjectName("FromStateCbox");

        horizontalLayout_3->addWidget(FromStateCbox);

        goesToLbl = new QLabel(horizontalLayoutWidget_3);
        goesToLbl->setObjectName("goesToLbl");

        horizontalLayout_3->addWidget(goesToLbl);

        ToStateCbox = new QComboBox(horizontalLayoutWidget_3);
        ToStateCbox->setObjectName("ToStateCbox");

        horizontalLayout_3->addWidget(ToStateCbox);

        enterSymbolsLbl = new QLabel(NFADialog);
        enterSymbolsLbl->setObjectName("enterSymbolsLbl");
        enterSymbolsLbl->setGeometry(QRect(10, 120, 91, 20));
        enterStatesLbl = new QLabel(NFADialog);
        enterStatesLbl->setObjectName("enterStatesLbl");
        enterStatesLbl->setGeometry(QRect(10, 10, 91, 16));
        enterTransLbl = new QLabel(NFADialog);
        enterTransLbl->setObjectName("enterTransLbl");
        enterTransLbl->setGeometry(QRect(10, 200, 111, 16));
        submitTransBtn = new QPushButton(NFADialog);
        submitTransBtn->setObjectName("submitTransBtn");
        submitTransBtn->setGeometry(QRect(100, 250, 100, 32));
        TotalTransLbl = new QLabel(NFADialog);
        TotalTransLbl->setObjectName("TotalTransLbl");
        TotalTransLbl->setGeometry(QRect(480, 50, 111, 16));
        numTransLbl = new QLabel(NFADialog);
        numTransLbl->setObjectName("numTransLbl");
        numTransLbl->setGeometry(QRect(590, 50, 31, 16));

        retranslateUi(NFADialog);

        testBtn->setDefault(false);


        QMetaObject::connectSlotsByName(NFADialog);
    } // setupUi

    void retranslateUi(QDialog *NFADialog)
    {
        NFADialog->setWindowTitle(QCoreApplication::translate("NFADialog", "Dialog", nullptr));
        StartCheckBox->setText(QCoreApplication::translate("NFADialog", "Start State?", nullptr));
        AcceptCheckBox->setText(QCoreApplication::translate("NFADialog", "Accept State", nullptr));
        startStateErrorLbl->setText(QString());
        transErrorLbl->setText(QString());
        buildBtn->setText(QCoreApplication::translate("NFADialog", "Build", nullptr));
        buildErrLbl->setText(QString());
        testBtn->setText(QCoreApplication::translate("NFADialog", "Test", nullptr));
        numSymLbl->setText(QCoreApplication::translate("NFADialog", "0", nullptr));
        symLbl->setText(QCoreApplication::translate("NFADialog", "Total Symbols:", nullptr));
        stateCounterLbl->setText(QCoreApplication::translate("NFADialog", "0", nullptr));
        statesLbl->setText(QCoreApplication::translate("NFADialog", "Total States:", nullptr));
        testInputLbl->setText(QString());
        testResultLbl->setText(QString());
        EnterStateBtn->setText(QCoreApplication::translate("NFADialog", "Enter", nullptr));
        stateNameLine->setText(QString());
        EnterSymBtn->setText(QCoreApplication::translate("NFADialog", "Enter", nullptr));
        symbolLine->setText(QString());
        goesToLbl->setText(QCoreApplication::translate("NFADialog", "Goes To", nullptr));
        enterSymbolsLbl->setText(QCoreApplication::translate("NFADialog", "Enter Symbols: ", nullptr));
        enterStatesLbl->setText(QCoreApplication::translate("NFADialog", "Enter States: ", nullptr));
        enterTransLbl->setText(QCoreApplication::translate("NFADialog", "Enter Transitions: ", nullptr));
        submitTransBtn->setText(QCoreApplication::translate("NFADialog", "Submit", nullptr));
        TotalTransLbl->setText(QCoreApplication::translate("NFADialog", "Total Transitions: ", nullptr));
        numTransLbl->setText(QCoreApplication::translate("NFADialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NFADialog: public Ui_NFADialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NFADIALOG_H
