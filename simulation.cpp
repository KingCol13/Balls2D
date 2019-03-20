#include "simulation.h"

#include <vector>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <random>

#ifndef PI
#define PI 3.14159265
#endif

Simulation::Simulation(int no_balls,double max_vel, double ball_radius, double cont_rad, double spacing)
{
    num_balls = no_balls;
    time = 0;
    double b_mass = 1;
    cont = new Container(5e5, 10);

    std::uniform_real_distribution<double> unif(0, max_vel);
    std::default_random_engine re;

    int bpr = 1;
    int ring_no = 0;
    double r_r = 0;
    int i,j;

    double vel[2];
    double pos[2];

    double r_theta;
    double r_gap = spacing;
    double arc_gap = spacing;



    for(i=0; i<num_balls; ++i, ++j){
            vel[0] = unif(re);
            vel[1] = unif(re);
            if(r_r >= cont_rad-ball_radius){
                printf("Ball position exceeded maximum.");
            }
            r_theta = (2*PI/bpr)*j;
            pos[0] = r_r*cos(r_theta);
            pos[1] = r_r*sin(r_theta);
            ball_list.push_back(Ball(pos, vel, b_mass, ball_radius));
            if(j%bpr == 0){
                j=0;
                ring_no+=1;
                r_r = 2*ring_no*ball_radius + r_gap*ring_no;
                bpr = floor(2*PI/(2*atan(ball_radius/r_r) + arc_gap/r_r));
            }
    }


    ball_list.push_back(*cont);
    num_balls++;

    //Resize the tcols array
    t_cols.resize(num_balls);
    for(i=0; i<num_balls; i++){
            t_cols[i].resize(num_balls, std::numeric_limits<double>::infinity());
    }

    //Fill the t_cols array with times to collision (make it upper triangular since it would be symmetric)
    for(i=0; i<num_balls;i++){
        for(j=i; j<num_balls; j++){
            if(i!=j){
                t_cols[i][j] = ball_list[i].time_to_collision(ball_list[j]);
            }
        }
    }
}

void Simulation::next_collision(){
    //Find time to nearest collision t_min in matrix
    double t_min = std::numeric_limits<double>::infinity();
    int i_min, j_min;
    int i, j;

    //TODO: optimise this so it only checks balls that just collided and compares with last tmin
    for(i=0;i<num_balls;i++){
        for(j=i; j<num_balls; j++){
            if(t_cols[i][j]<t_min){
                i_min = i;
                j_min = j;
                t_min = t_cols[i][j];
            }
        }
    }

    time += t_min;
    printf("t_min = %lg\n", t_min);


    /*TODO: Fix this pressure stuff
    //get velocities to work out pressure
    //I should use .copy(), I'm not sure why this works
    v1_before = ball1.vel()
    v2_before = ball2.vel()
    */

    //Collide the balls
    ball_list[i_min].collide(ball_list[j_min], t_min);

    /* TODO: More pressure stuff
    //Work out change in momentum
    if isinstance(ball1, Container) or isinstance(ball2, Container):
        v1_change = ball1.vel() - v1_before
        v2_change = ball2.vel() - v2_before
        self._total_momentum_change += ball1.mass()*nl.norm(v1_change) + ball2.mass()*nl.norm(v2_change)
    */

    //Move balls that didn't collide normally
    for(i=0; i<num_balls; i++){
        if(i!=i_min && i!=j_min){
            ball_list[i].moved(t_min);
        }
    }


    //Subtract t_min from t_cols for next time update (as we have moved forwards in time now compared to when t_cols was calculated)
    for(i=0; i<num_balls; i++){
        for(j=i;j<num_balls;j++){
            t_cols[i][j]-=t_min;
        }
    }


    //Update t_cols array keeping it upper triangular
    t_cols[i_min][j_min] = ball_list[i_min].time_to_collision(ball_list[j_min]);
    for(i=0; i<num_balls; i++){
        if(i!=i_min && i!=j_min){
            if(i>i_min){
                t_cols[i_min][i] = ball_list[i].time_to_collision(ball_list[i_min]);
            }
            else{
                t_cols[i][i_min] = ball_list[i].time_to_collision(ball_list[i_min]);
            }
            if(i>j_min){
                t_cols[j_min][i] = ball_list[i].time_to_collision(ball_list[j_min]);
            }
            else{
                t_cols[i][j_min] = ball_list[i].time_to_collision(ball_list[j_min]);
            }
        }
    }

}

void Simulation::run(int num_cols, bool animate, bool histos){
    int i;
    for(i=0; i<num_cols; i++){
        next_collision();
    }
}

Simulation::~Simulation()
{
    //dtor
}
