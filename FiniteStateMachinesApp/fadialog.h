#ifndef FADIALOG_H
#define FADIALOG_H

#include <QDialog>
#include <QGraphicsItem>
#include <QPainter>
#include <QPolygonF>
#include <set>
#include <unordered_map>
#include "fmachine.h"

namespace Ui {
class FADialog;
}

class FADialog : public QDialog
{
    Q_OBJECT

public:
    explicit FADialog(QWidget *parent = nullptr);
    ~FADialog();
private:
    Ui::FADialog *ui;

    bool start = false;
    bool accepting = false;
    bool startExists = false;
    std::string stateName;
    std::unordered_map<std::string, int> nameToState;
    std::unordered_map<int, std::string> stateToName;
    NFA nfa;
    int stateNum = 0;
    int startState = -1;
    int symbNum = 0;
    int transNum = 0;
private slots:

    void onStateEnter();

    void updateStart(int);

    void updateAccept(int);

    void onSymbEnter();

    void onTransSubmit();

    void displayGraph();

    void onBuildEnter();

    void onTestEnter();

};

//Every state needs the name of the state in it
//do this by binding text(name of state) to an ellipse(shape of the state)
class EllipseTextItem : public QGraphicsItem {
public:
    EllipseTextItem(const QRectF &ellipseRect, const QString &text,  QGraphicsItem *parent = nullptr)
        : QGraphicsItem(parent), m_ellipseRect(ellipseRect), m_text(text) {}

    QRectF boundingRect() const override {
        return m_ellipseRect;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        //draw ellipse
        painter->drawEllipse(m_ellipseRect);
        //draw text
        painter->drawText(m_ellipseRect, Qt::AlignCenter, m_text);

    }
private:
    QRectF m_ellipseRect;
    QString m_text;
};

#endif // FADIALOG_H
