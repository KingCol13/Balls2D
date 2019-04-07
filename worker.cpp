#include "worker.h"

Worker::Worker(renderArea *rendA, Simulation *simu)
{
    rend = rendA;
    sim = simu;

    printData = false;
}

void Worker::process(){
    while(rend->playing){
        sim->next_collision();
        if(printData){
            sim->printData();
            fflush(stdout);
        }
        rend->update();
        //QThread::msleep(5);
    }
}


Worker::~Worker(){
}
