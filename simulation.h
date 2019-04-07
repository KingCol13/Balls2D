#ifndef SIMULATION_H
#define SIMULATION_H

#include "container.h"
#include <vector>

class Simulation
{
    public:
        Simulation(int no_balls,double max_vel, double ball_radius, double cont_rad, double spacing);
        void next_collision();
        void run(int num_cols);
        void printData();
        virtual ~Simulation();
        std::vector<Ball> ball_list;
        int num_balls;
        long col_number;
    protected:
        double time;
        Container *cont;
        //Should make this protected:
        //std::vector<Ball> ball_list;
        std::vector<std::vector<double>> t_cols;

    private:
};

#endif // SIMULATION_H
