#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <chrono>
#include <cstdlib>
#include <ctime>

const int SIZE = 100000;
const int END_ADD_COUNT = 1000;
const int MIDDLE_POSITION = 50000;
const int MIDDLE_COUNT = 100;
const int INDEX_COUNT = 5;

int main()
{
    std::srand(std::time(0));

    std::array<int, SIZE> arrayNumbers;
    std::vector<int> vectorNumbers;
    std::list<int> listNumbers;

    for (int i = 0; i < SIZE; i++)
    {
        int number = std::rand() % 1000 + 1;

        arrayNumbers[i] = number;
        vectorNumbers.push_back(number);
        listNumbers.push_back(number);
    }

    std::vector<int> endNumbers;
    std::vector<int> middleNumbers;

    for (int i = 0; i < END_ADD_COUNT; i++)
    {
        endNumbers.push_back(std::rand() % 1000 + 1);
    }

    for (int i = 0; i < MIDDLE_COUNT; i++)
    {
        middleNumbers.push_back(std::rand() % 1000 + 1);
    }

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point finish;

    std::cout << "Sequential access" << std::endl;

    long long arraySum = 0;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++)
    {
        arraySum = arraySum + arrayNumbers[i];
    }

    finish = std::chrono::high_resolution_clock::now();

    long long arraySequentialTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Array sum: " << arraySum << std::endl;
    std::cout << "Array time: " << arraySequentialTime << " ns" << std::endl;

    long long vectorSum = 0;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < vectorNumbers.size(); i++)
    {
        vectorSum = vectorSum + vectorNumbers[i];
    }

    finish = std::chrono::high_resolution_clock::now();

    long long vectorSequentialTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Vector sum: " << vectorSum << std::endl;
    std::cout << "Vector time: " << vectorSequentialTime << " ns" << std::endl;

    long long listSum = 0;

    start = std::chrono::high_resolution_clock::now();

    for (std::list<int>::iterator it = listNumbers.begin(); it != listNumbers.end(); it++)
    {
        listSum = listSum + *it;
    }

    finish = std::chrono::high_resolution_clock::now();

    long long listSequentialTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "List sum: " << listSum << std::endl;
    std::cout << "List time: " << listSequentialTime << " ns" << std::endl;

    std::cout << std::endl;

    std::cout << "Random access" << std::endl;

    std::array<int, INDEX_COUNT> indexes = {0, 25000, 50000, 75000, 99999};

    long long arrayRandomSum = 0;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < INDEX_COUNT; i++)
    {
        arrayRandomSum = arrayRandomSum + arrayNumbers[indexes[i]];
    }

    finish = std::chrono::high_resolution_clock::now();
    long long arrayRandomTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Array random sum: " << arrayRandomSum << std::endl;
    std::cout << "Array time: " << arrayRandomTime << " ns" << std::endl;

    long long vectorRandomSum = 0;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < INDEX_COUNT; i++)
    {
        vectorRandomSum = vectorRandomSum + vectorNumbers[indexes[i]];
    }

    finish = std::chrono::high_resolution_clock::now();

    long long vectorRandomTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Vector random sum: " << vectorRandomSum << std::endl;
    std::cout << "Vector time: " << vectorRandomTime << " ns" << std::endl;

    long long listRandomSum = 0;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < INDEX_COUNT; i++)
    {
        std::list<int>::iterator it = listNumbers.begin();

        for (int j = 0; j < indexes[i]; j++)
        {
            it++;
        }

        listRandomSum = listRandomSum + *it;
    }

    finish = std::chrono::high_resolution_clock::now();

    long long listRandomTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "List random sum: " << listRandomSum << std::endl;
    std::cout << "List time: " << listRandomTime << " ns" << std::endl;

    std::cout << std::endl;

    std::cout << "Insert to the end" << std::endl;

    std::cout << "Array cannot add elements because array has fixed size." << std::endl;

    std::vector<int> vectorForEnd = vectorNumbers;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < END_ADD_COUNT; i++)
    {
        vectorForEnd.push_back(endNumbers[i]);
    }

    finish = std::chrono::high_resolution_clock::now();

    long long vectorEndTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Vector size after insert: " << vectorForEnd.size() << std::endl;
    std::cout << "Vector time: " << vectorEndTime << " ns" << std::endl;

    std::list<int> listForEnd = listNumbers;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < END_ADD_COUNT; i++)
    {
        listForEnd.push_back(endNumbers[i]);
    }

    finish = std::chrono::high_resolution_clock::now();

    long long listEndTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "List size after insert: " << listForEnd.size() << std::endl;
    std::cout << "List time: " << listEndTime << " ns" << std::endl;

    std::cout << std::endl;

    std::cout << "Insert to the middle" << std::endl;

    std::cout << "Array cannot insert elements because array has fixed size." << std::endl;

    std::vector<int> vectorForMiddle = vectorNumbers;

    start = std::chrono::high_resolution_clock::now();

    vectorForMiddle.insert(vectorForMiddle.begin() + MIDDLE_POSITION, middleNumbers.begin(), middleNumbers.end());

    finish = std::chrono::high_resolution_clock::now();

    long long vectorMiddleTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
    std::cout << "Vector size after middle insert: " << vectorForMiddle.size() << std::endl;
    std::cout << "Vector time: " << vectorMiddleTime << " ns" << std::endl;

    std::list<int> listForMiddle = listNumbers;

    start = std::chrono::high_resolution_clock::now();

    std::list<int>::iterator listMiddleIt = listForMiddle.begin();

    for (int i = 0; i < MIDDLE_POSITION; i++)
    {
        listMiddleIt++;
    }

    listForMiddle.insert(listMiddleIt, middleNumbers.begin(), middleNumbers.end());

    finish = std::chrono::high_resolution_clock::now();

    long long listMiddleTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "List size after middle insert: " << listForMiddle.size() << std::endl;
    std::cout << "List time: " << listMiddleTime << " ns" << std::endl;

    std::cout << std::endl;

    std::cout << "Delete from the middle" << std::endl;

    std::array<int, SIZE> arrayForDelete = arrayNumbers;
    int arrayLogicalSize = SIZE;

    start = std::chrono::high_resolution_clock::now();

    for (int i = MIDDLE_POSITION; i < arrayLogicalSize - MIDDLE_COUNT; i++)
    {
        arrayForDelete[i] = arrayForDelete[i + MIDDLE_COUNT];
    }

    arrayLogicalSize = arrayLogicalSize - MIDDLE_COUNT;

    finish = std::chrono::high_resolution_clock::now();

    long long arrayDeleteTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Array logical size after delete: " << arrayLogicalSize << std::endl;
    std::cout << "Array real size is still: " << arrayForDelete.size() << std::endl;
    std::cout << "Array time: " << arrayDeleteTime << " ns" << std::endl;

    std::vector<int> vectorForDelete = vectorNumbers;

    start = std::chrono::high_resolution_clock::now();

    vectorForDelete.erase(vectorForDelete.begin() + MIDDLE_POSITION,
                          vectorForDelete.begin() + MIDDLE_POSITION + MIDDLE_COUNT);

    finish = std::chrono::high_resolution_clock::now();

    long long vectorDeleteTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Vector size after delete: " << vectorForDelete.size() << std::endl;
    std::cout << "Vector time: " << vectorDeleteTime << " ns" << std::endl;

    std::list<int> listForDelete = listNumbers;

    start = std::chrono::high_resolution_clock::now();

    std::list<int>::iterator listDeleteStart = listForDelete.begin();

    for (int i = 0; i < MIDDLE_POSITION; i++)
    {
        listDeleteStart++;
    }

    std::list<int>::iterator listDeleteEnd = listDeleteStart;

    for (int i = 0; i < MIDDLE_COUNT; i++)
    {
        listDeleteEnd++;
    }

    listForDelete.erase(listDeleteStart, listDeleteEnd);

    finish = std::chrono::high_resolution_clock::now();

    long long listDeleteTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "List size after delete: " << listForDelete.size() << std::endl;
    std::cout << "List time: " << listDeleteTime << " ns" << std::endl;

    return 0;
}
