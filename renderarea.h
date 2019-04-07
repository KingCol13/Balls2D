#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QThread>
#include "simulation.h"

class renderArea : public QWidget
{
    Q_OBJECT
public:
    explicit renderArea(QWidget *parent = 0);
    Simulation *sim;
    void paintEvent(QPaintEvent *);
    bool playing;
    bool printData;
private slots:
    void slotColButtonClicked();
    void slotPlayButtonClicked(bool checked);
signals:

public slots:
};

#endif // RENDERAREA_H
