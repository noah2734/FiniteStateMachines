#include "dfadialog.h"
#include "qpainterpath.h"
#include "ui_dfadialog.h"
#include "machine.h"

#include <vector>
#include <string>

bool start = false;
bool acc = false;
bool startExists = false;
int stateCounter = 0;
int symbolCounter = 0;
int start_id;

DFA dfa;
Graph graph;

std::vector<std::string> connectedStates; // see onStateEnter and onTransEnter

DFADialog::DFADialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DFADialog)
{
    ui->setupUi(this);
    //for state data
    connect(ui->EnterStateBtn, &QPushButton::clicked, this, &DFADialog::onStateEnter);
    connect(ui->StartCheckBox, &QCheckBox::stateChanged, this, &DFADialog::updateStart);
    connect(ui->AcceptCheckBox, &QCheckBox::stateChanged, this, &DFADialog::updateAccept);

    ui->stateNameLine->setPlaceholderText("State Name");
    //for symbols
    connect(ui->EnterSymBtn, &QPushButton::clicked, this, &DFADialog::onSymbEnter);

    ui->symbolLine->setPlaceholderText("Symbol");
    //for transitions
    connect(ui->EnterTransBtn, &QPushButton::clicked, this, &DFADialog::onTransEnter);

    ui->gotoLine->setPlaceholderText("State Name");
    //for build/test button
    connect(ui->buildBtn, &QPushButton::clicked, this, &DFADialog::onBuildEnter);
    connect(ui->testBtn, &QPushButton::clicked, this, &DFADialog::onTestEnter);
    //for error labels
    ui->transErrorLbl->setStyleSheet("color: red");

    ui->startStateErrorLbl->setStyleSheet("color: red;");

    ui->buildErrBtn->setStyleSheet("color: red;");

}

DFADialog::~DFADialog()
{
    delete ui;
}

std::string startStateName; //use as starting point when getting transition input

void DFADialog::onStateEnter() {
    if (start && startExists) {
        ui->startStateErrorLbl->setText("You already have a start state.");
    } else {
        std::string name = ui->stateNameLine->text().toStdString();

        if (start) {
            startExists = true;
            startStateName = name;

            dfa.addState(name, start, acc);
            connectedStates.push_back(dfa.getState(name).name);

            //firstStateName = connectedStates[0];
            stateCounter++;

            ui->stateCounterLbl->setText(QString::number(stateCounter));
            ui->currStateLbl->setText(QString::fromStdString(name));
            ui->stateNameLine->setText("");

            qDebug() << "added START state with name " << name << " ACCEPT = " << acc;
        } else {
            ui->startStateErrorLbl->setText("");

            stateCounter++;

            ui->stateCounterLbl->setText(QString::number(stateCounter));

            dfa.addState(name, start, acc);

            ui->stateNameLine->setText("");
            qDebug() << "added state with name " << name << " ACCEPT = " << acc;
        }
    }
}

void DFADialog::updateStart(int state) {
    start = (state == Qt::Checked);
}

void DFADialog::updateAccept(int state) {
    acc = (state == Qt::Checked);
}

//for symbols
std::string firstSymbol;
void DFADialog::onSymbEnter() {
    if (ui->symbolLine->text().isEmpty()) {
        qDebug() << "no entry";
        return;
    }
    if(dfa.emptySymbols()) {
        firstSymbol = ui->symbolLine->text().toStdString();
        ui->OnSymbolLbl->setText(ui->symbolLine->text());
    }
    ui->numSymLbl->setText(QString::number(++symbolCounter));
    dfa.addSymbol(ui->symbolLine->text().toStdString());
    ui->symbolLine->setText("");

}

//int connectedStatesCounter = 0;

bool inConnectedStates(std::string stateName) {
    for (auto& st : connectedStates) {
        if (stateName == st) {
            return true;
        }
    }
    return false;
}

std::string fromStateName;
std::string toStateName;
std::string currSymbol;
int numTransCounter = 0; //to print num of transitions
int symbolIndex = 0; //use for dfa.getSymbol()
int stateIndex = 0; //use for connected states
bool reachedMax = false; // when max transitions, no more should be entered

void DFADialog::onTransEnter() {
    if (reachedMax) {
        ui->transErrorLbl->setText("You have entered every possible transition");
        return;
    }
    fromStateName = connectedStates[stateIndex];
    toStateName = ui->gotoLine->text().toStdString();
    currSymbol = dfa.getSymbol(symbolIndex);

    if (!inConnectedStates(toStateName) && dfa.stateExists(toStateName)) {
        connectedStates.push_back(dfa.getState(toStateName).name);
    } else if (!(dfa.stateExists(toStateName))) {
        ui->transErrorLbl->setText(QString::fromStdString(toStateName) + " does not exist!");
    }

    /*qDebug() << "From state: " << QString::fromStdString(fromStateName) << "\n";
    qDebug() << "On " << QString::fromStdString(currSymbol) << "\n";
    qDebug() << "To state: " << QString::fromStdString(toStateName) << "\n";
    qDebug() << "symbolIndex: " << QString::number(symbolIndex) << "\n";
    qDebug() << "stateIndex: " << QString::number(stateIndex) << "\n";*/

    //not sure if ill need a graph AND set of transitions, but whatever
    graph.addVertex(fromStateName);
    graph.addEdge(fromStateName, toStateName, currSymbol);
    dfa.addTransition(fromStateName, currSymbol, toStateName);
    ui->transErrorLbl->setText("");

    ui->numForTransLbl->setText(QString::number(++numTransCounter));

    symbolIndex++;

    //(numSymbols) transitions per state for DFA
    if (symbolIndex == dfa.getNumSymbols()) {
        symbolIndex = 0;
        if (stateIndex == connectedStates.size() - 1) {
            reachedMax = true;
            //print graph
            ui->textEdit->setText(QString::fromStdString(graph.toString()));
            return;
        }
        stateIndex++;
    }

    ui->currStateLbl->setText(QString::fromStdString(connectedStates[stateIndex]));
    ui->OnSymbolLbl->setText(QString::fromStdString(dfa.getSymbol(symbolIndex)));
}

void DFADialog::displayGraph() {
    //if build not finished, error label


    QGraphicsScene *scene = ui->machineView->scene();
    if (!scene) {
        scene = new QGraphicsScene(this);
        ui->machineView->setScene(scene);
    }

    //for each state in connected states, add line and arrow, saving location of each state that is currently part of the graph
    //for every transition coming out of a state, alter angle of line by a factor determined by the numSymbols in input alphabet
    //The position of the states will differ depending on how many states there are
    //i.e if there are 4 states it would be a rectangle, if there are 5, a pentagram.
    //I might eventually come up with a more sophisticated algorithm but for now this will do.
    std::unordered_map<std::string, std::pair<int, int>> stateLocations;
    std::pair<int, int> FromCoordinate = {0,0};
    std::pair<int, int> ToCoordinate = {0, 0};
    std::pair<int, int> arrowCoordinate = {0, 0};
    std::pair<int, int> ellipseCoordinate = {0, 0};
    std::pair<int, int> ellipseSize = {0, 0};
    bool startAdded = false;

    // Create a QPainterPath and add elements to it
    QPainterPath path;
    EllipseTextItem *item;
    QPolygonF arrowHead;
    QGraphicsPolygonItem* arrowItem;

    std::string currentState;
    int stindex = 0;
    int syndex = 0;

    for (auto& st : connectedStates) {
        if (!startAdded) {
            //set to where we want the start state positioned
            ToCoordinate.first = 50;
            //set relative to where toCoordinate is
            arrowCoordinate.first = 50;

            ellipseSize.first = 25;
            ellipseSize.second = 25;

            //Coordinates of ellipse describe the upper left corner of its frame
            //so its position changes depending on its size
            ellipseCoordinate.first = 50;
            ellipseCoordinate.second = -(ellipseSize.second / 2);

            path.moveTo(FromCoordinate.first, FromCoordinate.second);
            path.lineTo(ToCoordinate.first, ToCoordinate.second);
            //create arrow
            arrowHead << QPointF(arrowCoordinate.first, arrowCoordinate.second) << QPointF(arrowCoordinate.first - 5, arrowCoordinate.second + 3) << QPointF(arrowCoordinate.first - 5, arrowCoordinate.second - 3);
            //set ellipse and name of start state
            item = new EllipseTextItem(QRectF(ellipseCoordinate.first, ellipseCoordinate.second, ellipseSize.first, ellipseSize.second), QString::fromStdString(startStateName));

            arrowItem = scene->addPolygon(arrowHead);
            scene->addItem(item);
            //save location of start state
            stateLocations[startStateName] = ellipseCoordinate;

            startAdded = true;

            FromCoordinate.first = ellipseCoordinate.first + ellipseSize.first;
            FromCoordinate.second = 0;

            continue;
        }

        currentState = connectedStates[++stindex];
        for (auto& edge : graph.getEdges(currentState)) {
            auto it = stateLocations.find(currentState);
            if (it == stateLocations.end()) {
                path.moveTo(FromCoordinate.first, FromCoordinate.second);

                ToCoordinate.first = FromCoordinate.first + 50;
                ToCoordinate.second = FromCoordinate.second;

                arrowCoordinate.first = ToCoordinate.first;
                arrowCoordinate.second = ToCoordinate.second;

                path.lineTo(ToCoordinate.first, ToCoordinate.second);

                ellipseCoordinate.first = ToCoordinate.first;
                ellipseCoordinate.second = ToCoordinate.second;



                //create arrow
                arrowHead << QPointF(arrowCoordinate.first, arrowCoordinate.second) << QPointF(arrowCoordinate.first - 5, arrowCoordinate.second + 3) << QPointF(arrowCoordinate.first - 5, arrowCoordinate.second - 3);
                //set ellipse and name of start state
                item = new EllipseTextItem(QRectF(ellipseCoordinate.first, ellipseCoordinate.second - ellipseSize.second/2, ellipseSize.first, ellipseSize.second), QString::fromStdString(edge.first));
                //item = new EllipseTextItem(QRectF(100, 100, 25, 25), "FUCK");
                arrowItem = scene->addPolygon(arrowHead);
                scene->addItem(item);
            } else {
                qDebug() << "IDK what im doing tbh";
            }
        }



    }


    // Add path to scene
    QGraphicsPathItem *pathItem = scene->addPath(path);

    // Set pen and brush
    QPen pen(Qt::black);
    pen.setWidth(2);
    pathItem->setPen(pen);
    arrowItem->setPen(pen);
    arrowItem->setBrush(Qt::black);


    // Optionally set the scene rect if you want to specify the visible area
    // scene->setSceneRect(...);

    // Update the view
    scene->update();
    ui->machineView->update();
}


void DFADialog::onBuildEnter() {
    displayGraph();
}

void DFADialog::onTestEnter() {

}
