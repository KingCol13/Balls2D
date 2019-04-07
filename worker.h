#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QObject>

#include "simulation.h"
#include "renderarea.h"

class Worker : public QObject {
    Q_OBJECT
public:
    Worker(renderArea *rendA, Simulation *simu);
    ~Worker();
public slots:
    void process();
private:
    renderArea *rend;
    Simulation *sim;
    bool printData;
};

#endif // WORKER_H
