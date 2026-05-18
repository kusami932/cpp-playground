#include "circles.h"
using namespace std;

Circle::Circle(double radius)
{
    r = radius;
}

double Circle::area() const
{
    return PI * r * r;
}

double Circle::circumference() const
{
    return 2 * PI * r;
}

double Circle::getRadius() const
{
    return r;
}

string Circle::toString() const
{
    return string("Circle {radius = ") + realToString(r) + string("}");
}