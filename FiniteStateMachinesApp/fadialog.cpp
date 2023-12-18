#include "fadialog.h"
#include "ui_fadialog.h"
#include "fmachine.h"

#include <vector>
#include <string>
#include <set>


FADialog::FADialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FADialog)
{
    ui->setupUi(this);

    ui->stateNameLine->setPlaceholderText("State Name");

    connect(ui->EnterStateBtn, &QPushButton::clicked, this, &FADialog::onStateEnter);
    connect(ui->StartCheckBox, &QCheckBox::stateChanged, this, &FADialog::updateStart);
    connect(ui->AcceptCheckBox, &QCheckBox::stateChanged, this, &FADialog::updateAccept);

    ui->symbolLine->setPlaceholderText("Symbol");

    connect(ui->EnterSymBtn, &QPushButton::clicked, this, &FADialog::onSymbEnter);

    connect(ui->submitTransBtn, &QPushButton::clicked, this, &FADialog::onTransSubmit);

    connect(ui->buildBtn, &QPushButton::clicked, this, &FADialog::onBuildEnter);

    connect(ui->testBtn, &QPushButton::clicked, this, &FADialog::onTestEnter);

    ui->transErrorLbl->setStyleSheet("color: red");

    ui->startStateErrorLbl->setStyleSheet("color: red;");

    ui->buildErrLbl->setStyleSheet("color: red;");

    ui->symbErrorLbl->setStyleSheet("color: red;");

    ui->symbErrorLbl->setText("");

    ui->onSymbolCbox->addItem(QString::fromUtf8(u8"\u03B5")); // epsilon symbol
}

FADialog::~FADialog()
{
    delete ui;
}

void FADialog::updateStart(int state) {
    start = (state == Qt::Checked);
}

void FADialog::updateAccept(int state) {
    accepting = (state == Qt::Checked);
}

void FADialog::onStateEnter() {
    if (start && startExists) {
        ui->startStateErrorLbl->setText("Start state already exists");
        return;
    } else if (ui->stateNameLine->text().toStdString() == "") {
        ui->startStateErrorLbl->setText("State name cannot be empty");
        return;
    }

    ui->startStateErrorLbl->setText("");
    std::string stateName = ui->stateNameLine->text().toStdString();

    if (start) {
        startExists = true;
        startState = stateNum;
    }

    nfa.addState(stateNum, start, accepting);
    nameToState[stateName] = stateNum;
    stateToName[stateNum] = stateName;
    ui->FromStateCbox->addItem(QString::fromStdString(stateName));
    ui->ToStateCbox->addItem(QString::fromStdString(stateName));
    ui->stateNameLine->setText("");
    stateNum++;
    ui->stateCounterLbl->setText(QString::fromStdString(std::to_string(stateNum)));
}

void FADialog::onSymbEnter() {
    if (ui->symbolLine->text().toStdString() == "") {
        ui->symbErrorLbl->setText("Please enter a symbol.");
        return;
    }

    ui->symbErrorLbl->setText("");
    char symbol = (ui->symbolLine->text().toStdString())[0];
    nfa.addSymbol(symbol);
    ui->onSymbolCbox->addItem(QChar(symbol));
    ui->symbolLine->setText("");
    symbNum++;
    ui->numSymLbl->setText(QString::fromStdString(std::to_string(symbNum)));
}

void FADialog::onTransSubmit() {
    std::string fromState = ui->FromStateCbox->currentText().toStdString();
    char onSymbol = ui->onSymbolCbox->currentText().toStdString()[0];
    std::string toState = ui->ToStateCbox->currentText().toStdString();

    if (fromState == "" || toState == "") {
        ui->transErrorLbl->setStyleSheet("color: red");
        ui->transErrorLbl->setText("You need to add states!");
        return;
    } else {
        ui->transErrorLbl->setStyleSheet("color: green");
        ui->transErrorLbl->setText("Submitted successfully!");
    }

    nfa.addTransition(nameToState[fromState], onSymbol, nameToState[toState]);
    transNum++;
    ui->numTransLbl->setText(QString::fromStdString(std::to_string(transNum)));
    printTransitions();
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

void FADialog::displayGraph() {
     QGraphicsScene *scene = ui->machineView->scene();
    if (!scene) {
        scene = new QGraphicsScene(this);
        ui->machineView->setScene(scene);
    }

    std::unordered_map<int, QPointF> stateLocations;
    QPointF From(0, 0);
    QPointF control(0, 0);
    QPointF To(0, 0);
    QPointF arrow(0, 0);
    QPointF ellipse(0, 0);
    QPointF ellipseSize(25, 25);
    bool startAdded = false;

    QPainterPath path;
    QPainter painter(this);
    EllipseTextItem *item;
    QGraphicsEllipseItem *item1;
    QPolygonF arrowHead;
    QGraphicsPolygonItem* arrowItem;

    std::string currentState;
    int stindex = 0;
    int syndex = 0;

    std::set<int> states = nfa.getStates();
    std::set<int> acceptingStates = nfa.getAcceptStates();

    for (auto& st : states) { 
        if (states.size() == 2) {
            ellipse = QPoint(ellipse.x() + 100, ellipse.y());
        } else if (states.size() == 3) {
            if (stindex == 1) {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y() - 100);
            } else {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y() + 100);
            }
        } else if (states.size() == 4) {
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
        } else if (states.size() >= 5) {
            if (stindex == 1) {
                ellipse = QPointF(ellipse.x() + 100, ellipse.y());
            } else if ((states.size() % 2 == 0) && (stindex < states.size()/2 )) {
                ellipse = QPointF(ellipse.x() + 90, ellipse.y() + 90);
            } else if ((states.size() % 2 == 0) && (stindex == states.size()/2 )) {
                ellipse = QPointF(ellipse.x(), ellipse.y() + 100);
            } else if ((stindex != states.size() - 1) && (states.size() % 2 == 0) && (stindex > states.size()/2 - 1)) {
                ellipse = QPointF(ellipse.x() - 90, ellipse.y() + 90);
            } else if ((states.size() % 2 == 1) && (stindex <= states.size()/2)) {
                ellipse = QPointF(ellipse.x() + 90, ellipse.y() + 90);
            } else if ((stindex != states.size() - 1) && (states.size() % 2 == 1) && (stindex > states.size()/2)) {
                ellipse = QPointF(ellipse.x() - 90, ellipse.y() + 90);
            } else if (stindex == states.size() - 1) {
                ellipse = QPointF(ellipse.x() - 100, ellipse.y());
            }
        }
        item = new EllipseTextItem(QRectF(ellipse, QSizeF(ellipseSize.x(), ellipseSize.y())), QString::fromStdString(stateToName[st]));
        if (acceptingStates.find(st) != acceptingStates.end()) {
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
    int startNm = startState;
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
    for (auto& st : states) {
        std::vector<std::pair<char, int> > transitions = nfa.getTransitions(st);
        if (transitions.empty()) continue;

        for (auto& transition : transitions) {
            x1 = stateLocations[st].x();
            y1 = stateLocations[st].y();
            x2 = stateLocations[transition.second].x();
            y2 = stateLocations[transition.second].y();
            label = QChar(transition.first);
            int xlbl = 5;
            int ylbl = 7;
            qDebug() << transition.first;
            
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

}

void FADialog::onBuildEnter() {
    displayGraph();
}

void FADialog::printTransitions() {
    std::string toPrint = "";
    for (auto &pair : nfa.getTransitions()) {
        for (auto &transition : pair.second) {
            toPrint += stateToName[pair.first] + " -> " + transition.first + " -> " + stateToName[transition.second] + "\n";
        }
    }
    ui->textEdit->setText(QString::fromStdString(toPrint));

}

void FADialog::printHistory() {
    std::string toPrint = "";
    for (auto &pair : inputHistory) {
        if (pair.second) {
            toPrint += pair.first + "     \tACCEPTED\n";
        } else {
            toPrint += pair.first + "     \tREJECTED\n";
        }
    }
    ui->textEdit->setText(QString::fromStdString(toPrint));
}

void FADialog::onTestEnter() {
    std::string input = ui->testLine->text().toStdString();
    bool accepted = nfa.accepts(input);
    std::pair<std::string, bool> inputPair;
    inputPair.first = input;
    inputPair.second = accepted;
    inputHistory.push_back(inputPair);
    printHistory();
    if (accepted) {
        ui->testInputLbl->setStyleSheet("color: green");
        ui->testInputLbl->setText("ACCEPTED");
    } else {
        ui->testInputLbl->setStyleSheet("color: red");
        ui->testInputLbl->setText("REJECTED");
    }
}