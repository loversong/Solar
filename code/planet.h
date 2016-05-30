#ifndef _PLANET_H_
#define _PLANET_H_
#include "data.h"
#include <math.h>
class planet
{
private:
    int index;
    float mass;
    point position;
    point velocity;
    point accelerate;
public:
    planet();
    planet(int m);
    ~planet();
    void moveDay();

    void calAcc(planet x);
    int getIndex() const;
    float getMass() const;
    point getPos() const;
    point getVel() const;
    std::string getName() const;

    void massChange(float f);
    void speedChange(point add);
};
#endif
