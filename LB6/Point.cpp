#include <iostream>
#include <cmath>
#include "Point.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double xValue, double yValue)
{
    x = xValue;
    y = yValue;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

void Point::setX(double xValue)
{
    x = xValue;
}

void Point::setY(double yValue)
{
    y = yValue;
}

void Point::print()
{
    std::cout << "(" << x << "; " << y << ")" << std::endl;
}

double Point::distanceToOrigin()
{
    return std::sqrt(x * x + y * y);
}
