#include <iostream>
#include <array>
#include <vector>
#include <list>

int main()
{
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Array elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr[5] = 100;

    std::cout << "Cannot add element to array because array has fixed size." << std::endl;

    std::cout << "Array size: " << arr.size() << std::endl;
    std::cout << "First element: " << arr[0] << std::endl;
    std::cout << "Last element: " << arr[arr.size() - 1] << std::endl;

    std::cout << std::endl;

    std::cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec[5] = 100;

    vec.push_back(11);

    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "First element: " << vec[0] << std::endl;
    std::cout << "Last element: " << vec[vec.size() - 1] << std::endl;

    std::cout << std::endl;

    std::cout << "List elements: ";
    for (int number : lst)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::list<int>::iterator it = lst.begin();

    for (int i = 0; i < 5; i++)
    {
        it++;
    }

    *it = 100;

    lst.push_back(11);

    std::cout << "List size: " << lst.size() << std::endl;
    std::cout << "First element: " << lst.front() << std::endl;
    std::cout << "Last element: " << lst.back() << std::endl;

    return 0;
}
