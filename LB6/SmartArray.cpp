#include <iostream>
#include "SmartArray.h"

SmartArray::SmartArray(int sizeValue)
{
    if (sizeValue > 0)
    {
        size = sizeValue;
    }
    else
    {
        size = 1;
    }

    data = new int[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = 0;
    }
}

SmartArray::~SmartArray()
{
    delete[] data;
    std::cout << "Memory was freed" << std::endl;
}

void SmartArray::setElement(int index, int value)
{
    if (index >= 0 && index < size)
    {
        data[index] = value;
    }
    else
    {
        std::cout << "Index is out of range" << std::endl;
    }
}

int SmartArray::getElement(int index)
{
    if (index >= 0 && index < size)
    {
        return data[index];
    }

    std::cout << "Index is out of range" << std::endl;
    return 0;
}
