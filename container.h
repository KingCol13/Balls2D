#ifndef CONTAINER_H
#define CONTAINER_H

#include "ball.h"


class Container : public Ball
{
    public:
        Container(double massi, double radiusi); // : Ball(double posi[2], double veli[2], double massi, double radiusi);
        virtual ~Container();

    protected:

    private:
};

#endif // CONTAINER_H
