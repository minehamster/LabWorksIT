#include <iostream>
#include "DigitalClock.h"

int main()
{
    DigitalClock clock1(12, 30, 45);

    std::cout << "First clock:" << std::endl;
    clock1.display();

    std::cout << "After one tick:" << std::endl;
    clock1.tick();
    clock1.display();

    std::cout << std::endl;

    DigitalClock clock2(23, 59, 59);

    std::cout << "Second clock:" << std::endl;
    clock2.display();

    std::cout << "After one tick:" << std::endl;
    clock2.tick();
    clock2.display();

    std::cout << std::endl;

    DigitalClock clock3(25, 70, 90);
    std::cout << "Third clock with wrong values:" << std::endl;
    clock3.display();

    std::cout << std::endl;

    clock3.setHours(8);
    clock3.setMinutes(5);
    clock3.setSeconds(3);

    std::cout << "Third clock after setters:" << std::endl;
    clock3.display();

    std::cout << "Hours: " << clock3.getHours() << std::endl;
    std::cout << "Minutes: " << clock3.getMinutes() << std::endl;
    std::cout << "Seconds: " << clock3.getSeconds() << std::endl;

    std::cout << std::endl;

    clock3.setHours(30);
    clock3.setMinutes(80);
    clock3.setSeconds(100);

    std::cout << "Third clock after wrong setters:" << std::endl;
    clock3.display();

    return 0;
}
