#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->DFAButton, SIGNAL(clicked()), this, SLOT(onDFAClicked()));
    // Create a new QGraphicsScene
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 400, 300);  // Set the size of the scene

    // Add a rectangle to the scene
    QGraphicsRectItem *rect = new QGraphicsRectItem(50, 50, 100, 50);
    scene->addItem(rect);

    // Set the scene to the QGraphicsView
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::onDFAClicked() {

}*/

