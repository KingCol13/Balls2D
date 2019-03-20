#include "ball.h"
#include <iostream>
#include <cmath>
#include <limits>

#define C_THRESHOLD 10e-6

Ball::Ball(double posi[2], double veli[2], double massi, double radiusi)
{
    mass = massi;
    radius = radiusi;
    pos[0] = posi[0];
    pos[1] = posi[1];
    vel[0] = veli[0];
    vel[1] = veli[1];
}

double Ball::getMass(){
    return mass;
}

double Ball::getRadius(){
    return radius;
}

double *Ball::getPos(){
    return pos;
}

double *Ball::getVel(){
    return vel;
}

void Ball::moved(double dt){
    pos[0]+=dt*vel[0];
    pos[1]+=dt*vel[1];
}

double Ball::time_to_collision(Ball &other){

    double a = (vel[0]-other.vel[0])*(vel[0]-other.vel[0])+(vel[1]-other.vel[1])*(vel[1]-other.vel[1]);
    if(a==0){
        return std::numeric_limits<double>::infinity();
    }
    double b = 2 * ((vel[0]-other.vel[0])*(pos[0]-other.pos[0])+(vel[1]-other.vel[1])*(pos[1]-other.pos[1]));
    //TODO: Use c to know if they're already touching
    double c = (pos[0]-other.pos[0])*(pos[0]-other.pos[0])+(pos[1]-other.pos[1])*(pos[1]-other.pos[1]) - (radius + other.radius)*(radius + other.radius);

    double discrim = b*b-4*a*c;


    if(discrim<0){
        return std::numeric_limits<double>::infinity();
    }
    else{
        double t = (-b-sqrt(discrim))/(2*a);
        //if time<0 or if they're already touching choose greater solution.
        if(t<0 || c<C_THRESHOLD){
            t = (-b+sqrt(discrim))/(2*a);
        }
        if(t>0){
            return t;
        }
        else{
            return std::numeric_limits<double>::infinity();
        }
    }
}

void Ball::collide(Ball &other, double tcol){
    moved(tcol);
    other.moved(tcol);

    double r12[2] = {other.pos[0] - pos[0], other.pos[1] - pos[1]};
    double u12[2] = {other.vel[0] - vel[0], other.vel[1] - vel[1]};

    //v1 = self.__v + (((2*m2)*sp.dot(u12, r12))/((m1+m2)*(sp.dot(r12, r12))))*r12
    //v2 = other.__v - (((2*m1)*sp.dot(u12, r12))/((m1+m2)*(sp.dot(r12, r12))))*r12

    double k = (u12[0]*r12[0]+u12[1]*r12[1])/((mass+other.mass)*(r12[0]*r12[0]+r12[1]*r12[1]));

    vel[0]+=2*other.mass*k*r12[0];
    vel[1]+=2*other.mass*k*r12[1];
    other.vel[0] -= 2*mass*k*r12[0];
    other.vel[1] -= 2*mass*k*r12[1];
}

void Ball::printData(){
    if(radius>0){
        printf("\nBall:\n");
    }
    else{
        printf("\nContainer:\n");
    }
    printf("Position: (%lg, %lg)\n", pos[0], pos[1]);
    printf("Velocity: (%lg, %lg)\n", vel[0], vel[1]);
    printf("Mass: %lg, Radius: %lg\n", mass, radius);
}

Ball::~Ball()
{

}
