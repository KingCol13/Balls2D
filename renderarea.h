#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include "simulation.h"

class renderArea : public QWidget
{
    Q_OBJECT
public:
    explicit renderArea(QWidget *parent = 0);
    Simulation *sim;
    void paintEvent(QPaintEvent *);
private slots:
    void slotButtonClicked();
signals:

public slots:
};

#endif // RENDERAREA_H
