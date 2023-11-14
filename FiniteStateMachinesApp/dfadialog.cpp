#include "dfadialog.h"
#include "qpainterpath.h"
#include "ui_dfadialog.h"
#include "machine.h"

#include <vector>
#include <string>
//#include <QPair>
//a#include <QVector>

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

    ui->buildErrLbl->setStyleSheet("color: red;");

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

//quadrant refers to the quadrant of the circle that the endpoint connects to
QPolygonF createArrowhead(const QPointF& endPt, const QPointF& startPt, int quadrant) {
    QPolygonF arrowHead;

    QPointF arrowP1;
    QPointF arrowP2;

    switch(quadrant) {
        case 1:
            arrowP1 = QPointF(endPt.x() + 5,
                              endPt.y());
            arrowP2 = QPointF(endPt.x(),
                              endPt.y() + 5);
            break;
        case 2:
            arrowP1 = QPointF(endPt.x(),
                              endPt.y() + 5);
            arrowP2 = QPointF(endPt.x() - 5,
                              endPt.y());
            break;
        case 3:
            arrowP1 = QPointF(endPt.x(),
                              endPt.y() - 5);
            arrowP2 = QPointF(endPt.x() - 5,
                              endPt.y());
            break;
        case 4:
            arrowP1 = QPointF(endPt.x() + 5,
                              endPt.y());
            arrowP2 = QPointF(endPt.x(),
                              endPt.y() - 5);
            break;
        case 5: // horizntal left
            arrowP1 = QPointF(endPt.x() - (5*cos(3*M_PI_4)),
                              endPt.y() + 5*sin(3*M_PI_4));
            arrowP2 = QPointF(endPt.x() - (5*cos(5*M_PI_4)),
                              endPt.y() + (5*sin(5*M_PI_4)));
            break;
        case 6: // horizontal right
            arrowP1 = QPointF(endPt.x() + 5*cos(3*M_PI_4),
                              endPt.y() + 5*sin(3*M_PI_4));
            arrowP2 = QPointF(endPt.x() + 5*cos(5*M_PI_4),
                              endPt.y() + 5*sin(5*M_PI_4));
            break;
        case 7: //vertical up
            arrowP1 = QPointF(endPt.x() - 5*cos(M_PI_4),
                              endPt.y() - 5*sin(M_PI_4));
            arrowP2 = QPointF(endPt.x() - 5*cos(3*M_PI_4),
                              endPt.y() - 5*sin(3*M_PI_4));
            break;
        case 8: //vertical down
            arrowP1 = QPointF(endPt.x() - 5*cos(-M_PI_4),
                              endPt.y() - 5*sin(-M_PI_4));
            arrowP2 = QPointF(endPt.x() - 5*cos(5*M_PI_4),
                              endPt.y() - 5*sin(5*M_PI_4));
        
    }

    /*QPointF arrowSideOffset(cos(angle) * arrowHeadWidth, sin(angle) * arrowHeadWidth);

    QPointF arrowP1 = endPt + QPointF(sin(angle - M_PI / 3) * arrowHeadLength,
                                    cos(angle - M_PI / 3) * arrowHeadLength) - arrowSideOffset;
    QPointF arrowP2 = endPt + QPointF(sin(angle + M_PI / 3) * arrowHeadLength,
                                    cos(angle + M_PI / 3) * arrowHeadLength) + arrowSideOffset;
    */

    arrowHead << endPt << arrowP1 << arrowP2;

    return arrowHead;
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
    //i.e if there are 4 states it would be a diamond, if there are 5, a pentagram.
    //I might eventually come up with a more sophisticated algorithm but for now this will do.
    std::unordered_map<std::string, QPointF> stateLocations;
    QPointF From(0, 0);
    QPointF control(0, 0);
    QPointF To(0, 0);
    QPointF arrow(0, 0);
    QPointF ellipse(0, 0);
    QPointF ellipseSize(25, 25);
    bool startAdded = false;

    // Create a QPainterPath and add elements to it
    QPainterPath path;
    QPainter painter(this);
    EllipseTextItem *item;
    QGraphicsEllipseItem *item1;
    QPolygonF arrowHead;
    QGraphicsPolygonItem* arrowItem;

    std::string currentState;
    int stindex = 0;
    int syndex = 0;

    if (connectedStates.empty()) {
        ui->buildErrLbl->setText("You need to add transitions");
        return;
    }
    ui->buildErrLbl->setText("");
    //first add states
    for (auto& st : connectedStates) { 
        if (connectedStates.size() == 2) {
            ellipse = QPoint(ellipse.x() + 100, ellipse.y());
        } else if (connectedStates.size() == 3) {
            if (stindex == 1) {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y() - 100);
            } else {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y() + 100);
            }
        } else if (connectedStates.size() == 4) {
            switch (stindex) {
            case 0:
                ellipse = QPointF(ellipse.x() + 100, ellipse.y() + 100);
                break;
            case 1:
                ellipse = QPointF(ellipse.x() + 100, ellipse.y() - 100);
                break;
            case 2:
                ellipse = QPointF(ellipse.x() - 100, ellipse.y() - 100);
                break;
            case 3:
                ellipse = QPointF(ellipse.x() - 100, ellipse.y() + 100);
                break;
            }
        } else if (connectedStates.size() >= 5) {
            if (stindex == 1) {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y());
            } else if ((connectedStates.size() % 2 == 0) && (stindex < connectedStates.size()/2 )) {
                ellipse = QPointF(ellipse.x() + 90, ellipse.y() + 90);
            } else if ((connectedStates.size() % 2 == 0) && (stindex == connectedStates.size()/2 )) {
                ellipse = QPointF(ellipse.x(), ellipse.y() + 100);
            } else if ((stindex != connectedStates.size() - 1) && (connectedStates.size() % 2 == 0) && (stindex > connectedStates.size()/2 - 1)) {
                ellipse = QPointF(ellipse.x() - 90, ellipse.y() + 90);
            } else if ((connectedStates.size() % 2 == 1) && (stindex <= connectedStates.size()/2)) {
                ellipse = QPointF(ellipse.x() + 90, ellipse.y() + 90);
            } else if ((stindex != connectedStates.size() - 1) && (connectedStates.size() % 2 == 1) && (stindex > connectedStates.size()/2)) {
                ellipse = QPointF(ellipse.x() - 90, ellipse.y() + 90);
            } else if (stindex == connectedStates.size() - 1) {
                ellipse = QPointF(ellipse.x() - 100, ellipse.y());
            }
        }
        item = new EllipseTextItem(QRectF(ellipse, QSizeF(ellipseSize.x(), ellipseSize.y())), QString::fromStdString(st));
        if (dfa.getState(st).isAccept) {
            item1 = new QGraphicsEllipseItem(QRectF(QPointF(ellipse.x() + 2, ellipse.y() + 2), QSizeF(ellipseSize.x() - 4, ellipseSize.y() - 4)));
            scene->addItem(item1);
        }
        scene->addItem(item);

        stindex++;

        stateLocations[st] = ellipse;

        qDebug() << "(" << ellipse.x() << ", " << ellipse.y() << ")";
    }

    //add transitions
    //first add start arrow
    From = QPointF((stateLocations[startStateName].x() - 15), (stateLocations[startStateName].y() + (ellipseSize.y() / 2)));
    To = QPointF(stateLocations[startStateName].x(), stateLocations[startStateName].y() + (ellipseSize.y() / 2));

    path.moveTo(From);
    path.lineTo(To);

    arrowHead << To << QPointF(To.x() - 5, To.y() + 2.5) << QPointF(To.x() - 5, To.y() - 2.5);

    scene->addPolygon(arrowHead);

    stindex = 0;
    int x1;
    int y1;
    int x2;
    int y2;
    int q;
    QString label;
    QVector<QPolygonF> arrowheads;
    QVector<QPair<QString, QPointF>> textItems;
    for (auto& st : connectedStates) {
        for (auto& edge : graph.getEdges(st)) {
            x1 = stateLocations[st].x();
            y1 = stateLocations[st].y();
            x2 = stateLocations[edge.first].x();
            y2 = stateLocations[edge.first].y();
            label = QString::fromStdString(edge.second);
            qDebug() << edge.second;
            
            //if state a straight right of state b
            if ((x1 == x2) && (y1 == y2)) {
                /*if (y1 > 0) {
                    From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(4*M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(4*M_PI/3))));
                    To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(10*M_PI/6))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(10*M_PI/6))));      
                    control = QPointF(From.x(), From.y() - 10);          
                } else {
                    From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(2*M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(2*M_PI/3))));
                    To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(M_PI/3))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(M_PI/3))));      
                    control = QPointF(From.x(), From.y() + 10);   
                }*/
            } else if ((x1 < x2) && (y1 == y2)) {
                q = 6;
                From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(-M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(-M_PI/3))));
                To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(7*M_PI/6))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(7*M_PI/6))));                
                control = QPointF(From.x() + ((To.x() - From.x()) / 2), (From.y() + ((To.y() - From.y()) / 2)) - 10);
            } else if (x1 > x2 && (y1 == y2)) {
                q = 5;
                From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(5*M_PI/6))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(5*M_PI/6)))); 
                To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(M_PI/3))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(M_PI/3)))); 
                control = QPointF(From.x() + ((To.x() - From.x()) / 2), (From.y() + ((To.y() - From.y()) / 2)) + 10);
            } else if ((x1 == x2) && (y1 > y2)) {
                q = 8;
                From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(-M_PI/6))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(-M_PI/6))));
                To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(M_PI/6))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(M_PI/6))));
                control = QPointF(From.x() + ((To.x() - From.x()) / 2) + 10, (From.y() + ((To.y() - From.y()) / 2)));
            } else if ((x1 == x2) && (y1 < y2)) {
                q = 7;
                From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(2*M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(2*M_PI/3))));
                To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(4*M_PI/3))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(4*M_PI/3))));
                control = QPointF(From.x() + ((To.x() - From.x()) / 2) - 10, (From.y() + ((To.y() - From.y()) / 2)));
            } else if ((x1 < x2) && (y1 < y2)) {
                q = 3;
                From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(11*M_PI/6))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(11*M_PI/6))));
                To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(-M_PI/3))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(-M_PI/3))));
                control = QPointF(From.x() + ((To.x() - From.x()) / 2) + 10, (From.y() + ((To.y() - From.y()) / 2)) - 10);
            } else if ((x1 < x2) && (y1 > y2)) {
                q = 2;
                From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(-2*M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(-2*M_PI/3))));
                To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(7*M_PI/6))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(7*M_PI/6))));
                control = QPointF(From.x() + ((To.x() - From.x()) / 2) - 10, (From.y() + ((To.y() - From.y()) / 2)) - 10);
            } else if ((x1 > x2) && (y1 < y2)) {
                q = 4;
                From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(-4*M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(-4*M_PI/3))));
                To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(M_PI/6))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(M_PI/6))));
                control = QPointF(From.x() + ((To.x() - From.x()) / 2) + 10, (From.y() + ((To.y() - From.y()) / 2) + 10));
            } else if ((x1 > x2) && (y1 > y2)) {
                q = 1;
                From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(4*M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(4*M_PI/3))));
                To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(2*M_PI/3))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(2*M_PI/3))));
                control = QPointF(From.x() + ((To.x() - From.x()) / 2) - 10, (From.y() + ((To.y() - From.y()) / 2) + 10));
            }
            path.moveTo(From);
            path.quadTo(control, To);
            arrowheads.append(createArrowhead(To, From, q));
            textItems.append({label, QPointF(From.x() + ((To.x() - From.x()) / 2) - 5, (From.y() + ((To.y() - From.y()) / 2) - 7))});
            //painter.drawPolygon(arrowHead);
        }
    }
    for (int i = 0; i < arrowheads.size(); ++i) {
        scene->addPolygon(arrowheads[i]);
    }
    QBrush brush(Qt::black);
    for (const auto &item : textItems) {
        QGraphicsTextItem *textItem = new QGraphicsTextItem(item.first);
        textItem->setPos(item.second);
        textItem->setZValue(1);
        textItem->setFont(QFont("Arial", 10));
        textItem->setDefaultTextColor(brush.color());
        scene->addItem(textItem);
    }
    scene->addPath(path);
    // Add path to scene
    //QGraphicsPathItem *pathItem = scene->addPath(path);

    // Set pen and brush
    /*QPen pen(Qt::black);
    pen.setWidth(2);
    pathItem->setPen(pen);
    arrowItem->setPen(pen);
    arrowItem->setBrush(Qt::black);
    */


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
