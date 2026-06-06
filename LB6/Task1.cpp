#include <iostream>
#include "Counter.h"

int main()
{
    Counter counter(0, 3);

    std::cout << "Current value: " << counter.getCurrent() << std::endl;

    std::cout << "Increment:" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        counter.increment();
        std::cout << "Current value: " << counter.getCurrent() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Decrement:" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        counter.decrement();
        std::cout << "Current value: " << counter.getCurrent() << std::endl;
    }

    return 0;
}
