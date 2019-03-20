#include <iostream>
#include <stdio.h>
#include "simulation.h"

using namespace std;

int main(){

    Simulation sim(5, 1, 1, 10, 0.1);
    sim.ball_list[0].printData();
    sim.ball_list[1].printData();
    sim.run(10, 0, 0);
    sim.ball_list[0].printData();
    sim.ball_list[1].printData();

    return 0;
}
