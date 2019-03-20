#ifndef BALL_H
#define BALL_H


class Ball
{
    public:
        Ball(double posi[2], double veli[2], double massi, double radiusi);
        virtual ~Ball();
        double getMass();
        double getRadius();
        double *getPos();
        double *getVel();
        void moved(double dt);
        double time_to_collision(Ball &other);
        void collide(Ball &other, double tcol);
        void printData();

    protected:
        double mass;
        double radius;
        double pos[2];
        double vel[2];

    private:
};

#endif // BALL_H
