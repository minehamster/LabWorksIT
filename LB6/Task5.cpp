#include <iostream>
#include "SmartArray.h"

int main()
{
    std::cout << "Program started" << std::endl;

    {
        SmartArray array(5);

        array.setElement(0, 10);
        array.setElement(1, 20);
        array.setElement(2, 30);
        array.setElement(3, 40);
        array.setElement(4, 50);

        std::cout << "Array elements:" << std::endl;

        for (int i = 0; i < 5; i++)
        {
            std::cout << array.getElement(i) << " ";
        }

        std::cout << std::endl;

        array.setElement(10, 100);

        std::cout << "Wrong index value: " << array.getElement(10) << std::endl;
    }

    std::cout << "Block finished" << std::endl;
    std::cout << "Program finished" << std::endl;

    return 0;
}
