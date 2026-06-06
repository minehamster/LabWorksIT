#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student
{
private:
    std::string firstName;
    std::string lastName;
    int recordBookNumber;
    std::vector<int> grades;

public:
    Student(std::string firstNameValue, std::string lastNameValue, int recordBookNumberValue);
    ~Student();

    void addGrade(int grade);
    double getAverage() const;
    void printInfo() const;
};

#endif
