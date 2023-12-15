#include "nfadialog.h"
#include "ui_nfadialog.h"
#include "dfadialog.h"
#include "machine.h"

#include <vector>
#include <string>

NFADialog::NFADialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NFADialog)
{
    ui->setupUi(this);

    ui->stateNameLine->setPlaceholderText("State Name");

    connect(ui->EnterStateBtn, &QPushButton::clicked, this, &NFADialog::onStateEnter);
    connect(ui->StartCheckBox, &QCheckBox::stateChanged, this, &NFADialog::updateStart);
    connect(ui->AcceptCheckBox, &QCheckBox::stateChanged, this, &NFADialog::updateAccept);

    ui->symbolLine->setPlaceholderText("Symbol");

    connect(ui->EnterSymBtn, &QPushButton::clicked, this, &NFADialog::onSymbEnter);

    connect(ui->submitTransBtn, &QPushButton::clicked, this, &NFADialog::onTransSubmit);

    connect(ui->buildBtn, &QPushButton::clicked, this, &NFADialog::onBuildEnter);

    connect(ui->testBtn, &QPushButton::clicked, this, &NFADialog::onTestEnter);

    ui->transErrorLbl->setStyleSheet("color: red");

    ui->startStateErrorLbl->setStyleSheet("color: red;");

    ui->buildErrLbl->setStyleSheet("color: red;");

    ui->symbErrorLbl->setStyleSheet("color: red;");

    ui->symbErrorLbl->setText("");

    ui->onSymbolCbox->addItem(QString::fromUtf8(u8"\u03B5"));


}

NFADialog::~NFADialog()
{
    delete ui;
}

NFA nfa;
Graph ngraph;

std::vector<std::string> connectedStates1;

bool start1 = false;
bool accepting = false;
bool startExists1 = false;
std::string stateName;

void NFADialog::onStateEnter()
{
    if (start1 && startExists1) {
        ui->startStateErrorLbl->setText("You already have a start state.");
    } else if (ui->stateNameLine->text().toStdString() == "") {
        ui->startStateErrorLbl->setText("Please enter a state name.");
    } else {
        ui->startStateErrorLbl->setText("");
        std::string stateName = ui->stateNameLine->text().toStdString();

        if (start1) {
            startExists1 = true;
            nfa.setStartState(stateName);
            connectedStates1.push_back(stateName);
        }
        nfa.addState(stateName, start1, accepting);
        ui->FromStateCbox->addItem(QString::fromStdString(stateName));
        ui->ToStateCbox->addItem(QString::fromStdString(stateName));
        ui->stateNameLine->setText("");
    }
}

void NFADialog::updateStart(int state) {
    start1 = (state == Qt::Checked);
}

void NFADialog::updateAccept(int state) {
    accepting = (state == Qt::Checked);
}

void NFADialog::onSymbEnter() {
    if (ui->symbolLine->text().toStdString() == "") {
        ui->symbErrorLbl->setText("Please enter a symbol.");
        return;
    }
    ui->symbErrorLbl->setText("");
    std::string symbol = ui->symbolLine->text().toStdString();
    nfa.addSymbol(symbol);
    ui->onSymbolCbox->addItem(QString::fromStdString(symbol));
    ui->symbolLine->setText("");
}

bool inConnectedStates1(std::string stateName) {
    for (auto& st : connectedStates1) {
        if (stateName == st) {
            return true;
        }
    }
    return false;
}

void NFADialog::onTransSubmit() {
    std::string fromState = ui->FromStateCbox->currentText().toStdString();
    std::string toState = ui->ToStateCbox->currentText().toStdString();
    std::string onSymbol = ui->onSymbolCbox->currentText().toStdString();

    if (fromState == "" || toState == "") {
        ui->transErrorLbl->setStyleSheet("color: red");
        ui->transErrorLbl->setText("You need to add states!");
        return;
    } else {
        ui->transErrorLbl->setText("");
    }
    ngraph.addVertex(fromState);
    ngraph.addEdge(fromState, toState, onSymbol);
    nfa.addTransition(fromState, onSymbol, toState);
    if (!inConnectedStates1(fromState)) {
        connectedStates1.push_back(fromState);
    }
    if (!inConnectedStates1(toState)) {
        connectedStates1.push_back(toState);
    }
    ui->transErrorLbl->setStyleSheet("color: green");
    ui->transErrorLbl->setText("Transition submited!");
    ui->textEdit->setText(QString::fromStdString(ngraph.toString()));
}

QPolygonF createArrowhead1(const QPointF& endPt, const QPointF& startPt, int quadrant) {
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

void NFADialog::displayGraph(Graph* graph) {
    //if build not finished, error label
    QGraphicsScene *scene = ui->machineView->scene();
    if (!scene) {
        scene = new QGraphicsScene(this);
        ui->machineView->setScene(scene);
    }

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

    if (connectedStates1.empty()) {
        ui->buildErrLbl->setText("You need to add transitions");
        return;
    }
    ui->buildErrLbl->setText("");
    //first add states
    for (auto& st : connectedStates1) { 
        if (connectedStates1.size() == 2) {
            ellipse = QPoint(ellipse.x() + 100, ellipse.y());
        } else if (connectedStates1.size() == 3) {
            if (stindex == 1) {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y() - 100);
            } else {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y() + 100);
            }
        } else if (connectedStates1.size() == 4) {
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
        } else if (connectedStates1.size() >= 5) {
            if (stindex == 1) {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y());
            } else if ((connectedStates1.size() % 2 == 0) && (stindex < connectedStates1.size()/2 )) {
                ellipse = QPointF(ellipse.x() + 90, ellipse.y() + 90);
            } else if ((connectedStates1.size() % 2 == 0) && (stindex == connectedStates1.size()/2 )) {
                ellipse = QPointF(ellipse.x(), ellipse.y() + 100);
            } else if ((stindex != connectedStates1.size() - 1) && (connectedStates1.size() % 2 == 0) && (stindex > connectedStates1.size()/2 - 1)) {
                ellipse = QPointF(ellipse.x() - 90, ellipse.y() + 90);
            } else if ((connectedStates1.size() % 2 == 1) && (stindex <= connectedStates1.size()/2)) {
                ellipse = QPointF(ellipse.x() + 90, ellipse.y() + 90);
            } else if ((stindex != connectedStates1.size() - 1) && (connectedStates1.size() % 2 == 1) && (stindex > connectedStates1.size()/2)) {
                ellipse = QPointF(ellipse.x() - 90, ellipse.y() + 90);
            } else if (stindex == connectedStates1.size() - 1) {
                ellipse = QPointF(ellipse.x() - 100, ellipse.y());
            }
        }
        item = new EllipseTextItem(QRectF(ellipse, QSizeF(ellipseSize.x(), ellipseSize.y())), QString::fromStdString(st));
        if (nfa.getState(st).isAccept) {
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
    std::string startNm = nfa.getStartState();
    From = QPointF((stateLocations[startNm].x() - 15), (stateLocations[startNm].y() + (ellipseSize.y() / 2)));
    To = QPointF(stateLocations[startNm].x(), stateLocations[startNm].y() + (ellipseSize.y() / 2));

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
    for (auto& st : connectedStates1) {
        for (auto& edge : graph->getEdges(st)) {
            x1 = stateLocations[st].x();
            y1 = stateLocations[st].y();
            x2 = stateLocations[edge.first].x();
            y2 = stateLocations[edge.first].y();
            label = QString::fromStdString(edge.second);
            int xlbl = 5;
            int ylbl = 7;
            qDebug() << edge.second;
            
            //if state a straight right of state b
            if ((x1 == x2) && (y1 == y2)) {

                if (y1 >= 0) {
                    q = 7;
                    From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(4*M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(4*M_PI/3))));
                    To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(10*M_PI/6))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(10*M_PI/6))) - 2);      
                    control = QPointF(From.x(), From.y() - 50);    
                    ylbl = 20;   
                    xlbl = 0;   
                } else {
                    q = 8;
                    From = QPointF((x1 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(2*M_PI/3))), (y1 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(2*M_PI/3))));
                    To = QPointF((x2 + ellipseSize.x() / 2) + ((ellipseSize.x() / 2) * (cos(M_PI/3))), (y2 + ellipseSize.y() / 2) + ((ellipseSize.y() / 2) * (sin(M_PI/3))) + 2);      
                    control = QPointF(From.x(), From.y() + 50);   
                    ylbl = -20;
                    xlbl = 0;
                }
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
            arrowheads.append(createArrowhead1(To, From, q));
            textItems.append({label, QPointF(From.x() + ((To.x() - From.x()) / 2) - xlbl, (From.y() + ((To.y() - From.y()) / 2) - ylbl))});
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

void NFADialog::onBuildEnter() {
    displayGraph(&ngraph);
}

//switch between branches of compiutation
/*bool NFADialog::compute(std:string input) {
    std::vector<std::string> activeStates;
    activeStates.push_back(nfa.getStartState());
    int symIndex = 0;
}*/

void NFADialog::onTestEnter() {
    bool accepted = compute(ui->testStringLine->text().toStdString());
}