#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->DFARadio, &QRadioButton::toggled, this, &MainWindow::onRButtonToggled);
    connect(ui->NFARadio, &QRadioButton::toggled, this, &MainWindow::onRButtonToggled);
    connect(ui->PDARadio, &QRadioButton::toggled, this, &MainWindow::onRButtonToggled);
    //connect(ui->DFAButton, SIGNAL(clicked()), this, SLOT(onDFAClicked()));
    // Create a new QGraphicsScene
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 400, 300);  // Set the size of the scene

    // Add a rectangle to the scene
    //QGraphicsRectItem *rect = new QGraphicsRectItem(50, 50, 100, 50);
    //scene->addItem(rect);

    // Set the scene to the QGraphicsView
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::onDFAClicked() {

}*/

void MainWindow::onRButtonToggled(bool checked) {
    if (!checked) {
        return;
    }

    if (ui->DFARadio->isChecked()) {
        qDebug() << "DFA mode";
    } else if (ui->NFARadio->isChecked()) {
        qDebug() << "NFA mode";
    } else if (ui->PDARadio->isChecked()) {
        qDebug() << "PDA mode";
    }
}

