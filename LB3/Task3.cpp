#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

struct Student
{
    std::string name;
    int id;
    double gpa;
};

void printStudent(Student student)
{
    std::cout << "Name: " << student.name
              << ", ID: " << student.id
              << ", GPA: " << student.gpa << std::endl;
}

void printFirstFiveArray(std::array<Student, 1000> students)
{
    for (int i = 0; i < 5; i++)
    {
        printStudent(students[i]);
    }
}

void printFirstFiveVector(std::vector<Student> students)
{
    for (int i = 0; i < 5; i++)
    {
        printStudent(students[i]);
    }
}

void printFirstFiveList(std::list<Student> students)
{
    std::list<Student>::iterator it = students.begin();

    for (int i = 0; i < 5; i++)
    {
        printStudent(*it);
        it++;
    }
}

int main()
{
    std::srand(std::time(0));

    std::array<Student, 1000> arrayStudents;
    std::vector<Student> vectorStudents;
    std::list<Student> listStudents;

    for (int i = 0; i < 1000; i++)
    {
        Student student;

        student.name = "Student_" + std::to_string(i + 1);
        student.id = i + 1;
        student.gpa = (std::rand() % 301 + 100) / 100.0;

        arrayStudents[i] = student;
        vectorStudents.push_back(student);
        listStudents.push_back(student);
    }

    std::cout << "Sort by GPA descending" << std::endl;

    std::sort(arrayStudents.begin(), arrayStudents.end(),
        [](Student first, Student second)
        {
            return first.gpa > second.gpa;
        });

    std::sort(vectorStudents.begin(), vectorStudents.end(),
        [](Student first, Student second)
        {
            return first.gpa > second.gpa;
        });

    listStudents.sort(
        [](Student first, Student second)
        {
            return first.gpa > second.gpa;
        });

    std::cout << "Array first 5 students:" << std::endl;
    printFirstFiveArray(arrayStudents);

    std::cout << "Vector first 5 students:" << std::endl;
    printFirstFiveVector(vectorStudents);

    std::cout << "List first 5 students:" << std::endl;
    printFirstFiveList(listStudents);

    std::cout << std::endl;

    std::cout << "Sort by ID ascending" << std::endl;

    std::sort(arrayStudents.begin(), arrayStudents.end(),
        [](Student first, Student second)
        {
            return first.id < second.id;
        });

    std::sort(vectorStudents.begin(), vectorStudents.end(),
        [](Student first, Student second)
        {
            return first.id < second.id;
        });

    listStudents.sort(
        [](Student first, Student second)
        {
            return first.id < second.id;
        });

    std::cout << "Array first 5 students:" << std::endl;
    printFirstFiveArray(arrayStudents);

    std::cout << "Vector first 5 students:" << std::endl;
    printFirstFiveVector(vectorStudents);

    std::cout << "List first 5 students:" << std::endl;
    printFirstFiveList(listStudents);

    std::cout << std::endl;

    std::cout << "Sort by name lexicographically" << std::endl;

    std::sort(arrayStudents.begin(), arrayStudents.end(),
        [](Student first, Student second)
        {
            return first.name < second.name;
        });
    std::sort(vectorStudents.begin(), vectorStudents.end(),
        [](Student first, Student second)
        {
            return first.name < second.name;
        });

    listStudents.sort(
        [](Student first, Student second)
        {
            return first.name < second.name;
        });

    std::cout << "Array first 5 students:" << std::endl;
    printFirstFiveArray(arrayStudents);

    std::cout << "Vector first 5 students:" << std::endl;
    printFirstFiveVector(vectorStudents);

    std::cout << "List first 5 students:" << std::endl;
    printFirstFiveList(listStudents);

    return 0;
}
