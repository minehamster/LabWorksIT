#include <iostream>
#include "Student.h"

Student::Student(std::string firstNameValue, std::string lastNameValue, int recordBookNumberValue)
{
    firstName = firstNameValue;
    lastName = lastNameValue;
    recordBookNumber = recordBookNumberValue;
}

Student::~Student()
{
    std::cout << "Memory for student " << firstName << " was freed" << std::endl;
}

void Student::addGrade(int grade)
{
    if (grade >= 2 && grade <= 5)
    {
        grades.push_back(grade);
        std::cout << "Grade was added" << std::endl;
    }
    else
    {
        std::cout << "Wrong grade" << std::endl;
    }
}

double Student::getAverage() const
{
    if (grades.size() == 0)
    {
        return 0;
    }

    int sum = 0;

    for (int i = 0; i < grades.size(); i++)
    {
        sum += grades[i];
    }

    return (double)sum / grades.size();
}

void Student::printInfo() const
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Record book number: " << recordBookNumber << std::endl;

    std::cout << "Grades: ";

    if (grades.size() == 0)
    {
        std::cout << "No grades";
    }
    else
    {
        for (int i = 0; i < grades.size(); i++)
        {
            std::cout << grades[i] << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "Average grade: " << getAverage() << std::endl;
}
