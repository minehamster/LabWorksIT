#include <iostream>
#include <fstream>
#include <string>

struct Student{
    std::string name;
    int age;
    double grade;
};

void addStudentToFile(std::string fileName){
    Student student;

    std::cout << "Enter student name: ";
    std::cin >> student.name;

    std::cout << "Enter student age: ";
    std::cin >> student.age;

    std::cout << "Enter student grade: ";
    std::cin >> student.grade;

    std::ofstream file(fileName, std::ios::app);

    if (!file.is_open()){
        std::cout << "Error: file was not opened for writing" << std::endl;
        return;
    }

    file << student.name << " " << student.age << " " << student.grade << std::endl;

    if (file.fail()){
        std::cout << "Error: data was not written" << std::endl;
    }
    else{
        std::cout << "Student was added to file" << std::endl;
    }

    file.close();
}

void readStudentsFromFile(std::string fileName){
    Student student;

    std::ifstream file(fileName);

    if (!file.is_open()){
        std::cout << "Error: file was not opened for reading" << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "Students from file:" << std::endl;

    while (file >> student.name >> student.age >> student.grade){
        std::cout << "Name: " << student.name << std::endl;
        std::cout << "Age: " << student.age << std::endl;
        std::cout << "Grade: " << student.grade << std::endl;
        std::cout << std::endl;
    }

    if (file.bad()){
        std::cout << "Error: problem while reading file" << std::endl;
    }

    file.close();
}

int main(){
    std::string fileName = "students.txt";

    int choice = 0;

    while (choice != 3){
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add student" << std::endl;
        std::cout << "2. Show students" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1){
            addStudentToFile(fileName);
        }
        else if (choice == 2){
            readStudentsFromFile(fileName);
        }
        else if (choice == 3){
            std::cout << "Program finished" << std::endl;
        }
        else{
            std::cout << "Wrong choice" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
