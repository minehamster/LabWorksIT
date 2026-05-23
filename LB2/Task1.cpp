#include <iostream>
#include <string>

enum class Status {
    Excellent = 4,
    Good = 3,
    Satisfactory = 2,
    Unsatisfactory = 1
};

struct Student {
    int id;
    std::string name;
    Status status;
};

std::string statusToString(Status s) {
    switch(s) {
        case Status::Excellent:       return "Excellent";
        case Status::Good:            return "Good";
        case Status::Satisfactory:    return "Satisfactory";
        case Status::Unsatisfactory:  return "Unsatisfactory";
        default:              return "Unknown";
    }
}

int main(){
    int tempStatus;
    Student student;

    std::cout << "Enter student's ID: ";
    std::cin >> student.id;
    std::cin.ignore();
    std::cout << "Enter student's name: ";
    std::getline(std::cin, student.name);
    std::cout << "Enter student's grade: ";
    std::cin >> tempStatus;

    student.status = static_cast<Status>(tempStatus);

    std::cout << "Student ID: " << student.id << std::endl;
    std::cout << "Student name: " << student.name << std::endl;
    std::cout << "Student status: " << statusToString(student.status) << std::endl;
    std::cout << "Size of structure: " << sizeof(student) << std::endl;
    std::cout << "Size of array: " << sizeof(int[4]) << std::endl;
    return 0;
}
