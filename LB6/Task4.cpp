#include <iostream>
#include "Student.h"

int main()
{
    Student student1("Alex", "Ivanov", 1001);

    student1.addGrade(5);
    student1.addGrade(4);
    student1.addGrade(5);
    student1.addGrade(1);

    std::cout << std::endl;

    student1.printInfo();

    std::cout << std::endl;

    Student student2("Maria", "Petrova", 1002);

    student2.addGrade(3);
    student2.addGrade(4);
    student2.addGrade(5);

    std::cout << std::endl;

    student2.printInfo();

    std::cout << std::endl;

    return 0;
}
