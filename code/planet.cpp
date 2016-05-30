#include "planet.h"

planet::planet()
{;}

planet::planet(int m): index(m), mass(starMass[m]),
    position(starInitPosition[m] / shrinkCoeff[m]),
    velocity(starInitVelocity[m])
{
    accelerate.x = 0;
    accelerate.y = 0;
    accelerate.z = 0;
}

planet::~planet()
{;}

void planet::moveDay()
{
    velocity = velocity + accelerate * 100;
    position = position + velocity / 100 / shrinkCoeff[index];
    accelerate.x = 0;
    accelerate.y = 0;
    accelerate.z = 0;
}

void planet::calAcc(planet x)
{
    if (index == 10)
    {
        point tmp;
        tmp.x = 0;
        tmp.y = 0;
        tmp.z = 0;
        accelerate = accelerate + gravity(x.getMass(), position * shrinkCoeff[index], tmp);
        return;
    }
    accelerate = accelerate + gravity(x.getMass(), position * shrinkCoeff[index], x.getPos() * shrinkCoeff[x.getIndex()]);
}

int planet::getIndex() const
{return index;}

float planet::getMass() const
{return mass;}

point planet::getPos() const
{return position;}

point planet::getVel() const
{return velocity;}

std::string planet::getName() const
{return starName[index];}

void planet::massChange(float f)
{mass = starMass[index] * f;}

void planet::speedChange(point add)
{velocity = velocity + add;}
