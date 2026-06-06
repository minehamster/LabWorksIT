#ifndef POINT_H
#define POINT_H

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double xValue, double yValue);

    double getX();
    double getY();

    void setX(double xValue);
    void setY(double yValue);

    void print();
    double distanceToOrigin();
};

#endif
