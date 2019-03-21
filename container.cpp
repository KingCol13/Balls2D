#include "container.h"

double zeros[2] = {0,0};

Container::Container(double massi, double radiusi) : Ball(zeros, zeros, massi, -radiusi)
{
}

Container::~Container()
{
    //dtor
}
