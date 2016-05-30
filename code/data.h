#ifndef _DATA_H_
#define _DATA_H_
#include <string>
#include <iostream>
#include <cmath>

#define PI 3.1415926
//The unit is earthMass,AU,day.
static float G = 8.9242 * pow(10, -10);
struct point
{
	float x, y, z;
};

static std::string starName[11] = {"Sun", "Mercury", "Venus", "Earth",
                                   "Mars", "Jupiter", "Saturn", "Uranus",
                                   "Nepture", "Pluto", "Moon"
                                  };
//The earth mass is regarded as 1.
static float starMass[11] = {333400, 0.055, 0.815, 1, 0.107, 317.832, 95.16,
                             14.54, 17.15, 0.00245, 0.0123
                            };

//The unit is AU.
static  point starInitPosition[11] = {{0, 0, 0},
	{ 0.21432, 0.31774, 0.04705},
	{ -0.64248, 0.32736, 0.04284},
	{ 1, 0, 0},
	{ -1.46387, -0.41976, 0.04919},
	{ -2.19846, -4.71462, 0.11896},
	{ -4.47319, 8.41285, 0.41268},
	{ 17.39166, 8.10987, 0.25246},
	{ -17.23862, 24.6193, 0.92875},
	{ 33.03540, 18.23651, 11.60871},
	{ 0.00255, -0.0002231, 0.0002239}
};
//The moon's location is calculated from the earth.

//The unit is 0.01AU per day.
static point starInitVelocity[11] = {{0, 0, 0},
	{ -2.30202, 1.55567, 0},
	{ -0.91756, -1.79523, 0},
	{ 0, 1.72621, 0},
	{ 0.38589, -1.34381, 0},
	{ 0.68727, -0.31619, 0},
	{ -0.49359, -0.26238, 0},
	{ -0.16672, 0.35746, 0},
	{ -0.15206, -0.27555, 0},
	{ -0.13219, 0.24064, 0},
	{ 0.0050254, 0.058249, 0}
};

static float shrinkCoeff[11] = {1, 0.35, 0.33, 0.30, 0.35, 0.94,
                                1.44, 2.49, 3.41, 3.90, 0.005
                               };

static float starRadius[11] = {0.055, 0.01, 0.015, 0.02, 0.018, 0.043, 0.04, 0.025, 0.032, 0.018, 0.01};

static point operator+ (point x1, point x2)
{
	point ret;
	ret.x = x1.x + x2.x;
	ret.y = x1.y + x2.y;
	ret.z = x1.z + x2.z;
	return ret;
}

static point operator- (point x1, point x2)
{
	point ret;
	ret.x = x1.x - x2.x;
	ret.y = x1.y - x2.y;
	ret.z = x1.z - x2.z;
	return ret;
}

static point operator/ (point x0, float i)
{
	point ret;
	ret.x = x0.x / i;
	ret.y = x0.y / i;
	ret.z = x0.z / i;
	return ret;
}

static point operator* (point x0, float i)
{
	point ret;
	ret.x = x0.x * i;
	ret.y = x0.y * i;
	ret.z = x0.z * i;
	return ret;
}

static float distance(point x1, point x2)
{
	float ret;
	ret = (x1.x - x2.x) * (x1.x - x2.x) + (x1.y - x2.y) * (x1.y - x2.y) + (x1.z - x2.z) * (x1.z - x2.z);
	ret = pow(ret, 0.5);
	return ret;
}

static point gravity(float m, point a, point b)
{
	float l;
	point ret;
	l = distance(a, b);
	ret.x = G * m / pow(l, 3) * (b.x - a.x);
	ret.y = G * m / pow(l, 3) * (b.y - a.y);
	ret.z = G * m / pow(l, 3) * (b.z - a.z);
	return ret;
}
#endif
