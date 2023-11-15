#ifndef DFADIALOG_H
#define DFADIALOG_H

#include <QDialog>
#include <QGraphicsItem>
#include <QPainter>
#include <QPolygonF>

namespace Ui {
class DFADialog;
}

class DFADialog : public QDialog
{
    Q_OBJECT

public:
    explicit DFADialog(QWidget *parent = nullptr);
    ~DFADialog();

private:
    Ui::DFADialog *ui;
private slots:
    //for states
    void onStateEnter();

    void updateStart(int);

    void updateAccept(int);
    //for symbols
    void onSymbEnter();
    //for transitions
    void onTransEnter();
    //for building/testing
    void onBuildEnter();

    void displayGraph();

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

#endif // DFADIALOG_H
