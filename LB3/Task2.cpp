#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    std::array<int, 101> arr;
    std::vector<int> vec;
    std::list<int> lst;

    int arraySize = 100;

    for (int i = 0; i < 100; i++)
    {
        int number = std::rand() % 1000 + 1;

        arr[i] = number;
        vec.push_back(number);
        lst.push_back(number);
    }

    std::cout << "Initial array size: " << arraySize << std::endl;
    std::cout << "Initial vector size: " << vec.size() << std::endl;
    std::cout << "Initial list size: " << lst.size() << std::endl;

    std::cout << std::endl;

    // Work with array

    std::array<int, 101>::iterator arrIt = arr.begin() + 50;

    for (std::array<int, 101>::iterator it = arr.begin() + arraySize; it != arrIt; it--)
    {
        *it = *(it - 1);
    }

    *arrIt = 999;
    arraySize++;

    arrIt = arr.begin() + 25;

    for (std::array<int, 101>::iterator it = arrIt; it != arr.begin() + arraySize - 1; it++)
    {
        *it = *(it + 1);
    }

    arraySize--;

    arrIt = arr.begin();

    while (arrIt != arr.begin() + arraySize)
    {
        if (*arrIt > 500)
        {
            for (std::array<int, 101>::iterator it = arrIt; it != arr.begin() + arraySize - 1; it++)
            {
                *it = *(it + 1);
            }

            arraySize--;
        }
        else
        {
            arrIt++;
        }
    }

    std::cout << "Array remaining elements: " << arraySize << std::endl;

    // Work with vector

    std::vector<int>::iterator vecIt = vec.begin();

    for (int i = 0; i < 50; i++)
    {
        vecIt++;
    }

    vec.insert(vecIt, 999);

    vecIt = vec.begin();

    for (int i = 0; i < 25; i++)
    {
        vecIt++;
    }

    vec.erase(vecIt);

    vecIt = vec.begin();

    while (vecIt != vec.end())
    {
        if (*vecIt > 500)
        {
            vecIt = vec.erase(vecIt);
        }
        else
        {
            vecIt++;
        }
    }

    std::cout << "Vector remaining elements: " << vec.size() << std::endl;

    // Work with list

    std::list<int>::iterator listIt = lst.begin();

    for (int i = 0; i < 50; i++)
    {
        listIt++;
    }

    lst.insert(listIt, 999);

    listIt = lst.begin();

    for (int i = 0; i < 25; i++)
    {
        listIt++;
    }

    lst.erase(listIt);

    listIt = lst.begin();

    while (listIt != lst.end())
    {
        if (*listIt > 500)
        {
            listIt = lst.erase(listIt);
        }
        else
        {
            listIt++;
        }
    }

    std::cout << "List remaining elements: " << lst.size() << std::endl;


    return 0;
}
