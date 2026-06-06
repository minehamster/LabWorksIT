#include <iostream>
#include "Point.h"

int main()
{
    Point point1;
    Point point2(3, 4);

    std::cout << "First point: ";
    point1.print();

    std::cout << "Distance to origin: " << point1.distanceToOrigin() << std::endl;

    std::cout << std::endl;

    std::cout << "Second point: ";
    point2.print();

    std::cout << "Distance to origin: " << point2.distanceToOrigin() << std::endl;

    std::cout << std::endl;

    point1.setX(6);
    point1.setY(8);

    std::cout << "First point after changes: ";
    point1.print();

    std::cout << "X: " << point1.getX() << std::endl;
    std::cout << "Y: " << point1.getY() << std::endl;
    std::cout << "Distance to origin: " << point1.distanceToOrigin() << std::endl;

    return 0;
}
