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

    std::cin >> student.id;
    std::cin.ignore();
    std::getline(std::cin, student.name);
    std::cin >> tempStatus;

    student.status = static_cast<Status>(tempStatus);

    std::cout << student.id;
    std::cout << student.name;
    std::cout << statusToString(student.status);
    return 0;
}
