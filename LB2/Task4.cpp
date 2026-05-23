#include <iostream>
#include <string>

struct Address {
    std::string street;
    int house;
    int apartment;
};

struct Person {
    std::string fullName;
    int age;
    Address address;
};

struct FlatPerson {
    std::string fullName;
    int age;
    std::string street;
    int house;
    int apartment;
};

void inputPersons(Person arr[], int size) {
    std::cout << "Data entry\n";
    for (int i = 0; i < size; i++) {
        std::cout << "\nHuman " << i + 1 << ":\n";
        
        std::cout << "Full name: ";
        std::getline(std::cin >> std::ws, arr[i].fullName); 
        
        std::cout << "Age: ";
        std::cin >> arr[i].age;
        
        std::cout << "Street: ";
        std::getline(std::cin >> std::ws, arr[i].address.street);
        
        std::cout << "House: ";
        std::cin >> arr[i].address.house;
        
        std::cout << "Apartment: ";
        std::cin >> arr[i].address.apartment;
    }
}

void printAllPersons(const Person arr[], int size) {
    std::cout << "\nList of all people:\n";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i].fullName << " (Age: " << arr[i].age << ")\n";
        std::cout << "Adress: St. " << arr[i].address.street 
                  << ", h. " << arr[i].address.house 
                  << ", ap. " << arr[i].address.apartment << "\n\n";
    }
}

void searchByStreet(const Person arr[], int size, const std::string& targetStreet) {
    std::cout << "Search results (Street: " << targetStreet << "):\n";
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].address.street == targetStreet) {
            std::cout << "Found: " << arr[i].fullName 
                      << " (House " << arr[i].address.house << ")\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Nobody lives on this street\n";
    }
}

int main() {
    const int SIZE = 3;
    Person people[SIZE];

    inputPersons(people, SIZE);
    printAllPersons(people, SIZE);

    std::string searchStreet;
    std::cout << "Enter the street name to search:";
    std::getline(std::cin >> std::ws, searchStreet);
    searchByStreet(people, SIZE, searchStreet);

    std::cout << "\nDirect access demonstration\n";
    std::cout << "First person street: " << people[0].address.street << "\n";
    std::cout << "\nSize comparizon (sizeof)\n";
    std::cout << "Size of Person (nested): " << sizeof(Person) << " bytes\n";
    std::cout << "Size of FlatPerson (flat): " << sizeof(FlatPerson) << " bytes\n";

    return 0;
}
