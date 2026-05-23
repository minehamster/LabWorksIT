#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

enum VehicleType {
    Car = 1,
    Truck = 2,
    Motorcycle = 3
};

struct Engine {
    int power;       
    double volume;   
};

struct Vehicle {
    VehicleType type;
    std::string model;
    Engine engine;
};


struct FlatVehicle {
    std::string typeStr; 
    std::string model;
    int power;         
    double volume;
};


std::string getTypeString(VehicleType type) {
    switch (type) {
        case Car: return "Car";
        case Truck: return "Truck";
        case Motorcycle: return "Motorcycle";
        default: return "Unknown";
    }
}

void inputVehicles(Vehicle arr[], int size) {
    std::cout << "Enter 5 vehicles\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "\nVehicle number " << i + 1 << ":\n";
        
        int typeChoice;
        std::cout << "Type (1-Car, 2-Truck, 3-Motorcycle): ";
        std::cin >> typeChoice;
        arr[i].type = static_cast<VehicleType>(typeChoice);

        std::cout << "Model: ";
        std::getline(std::cin >> std::ws, arr[i].model);

        std::cout << "Engine power (horse powers): ";
        std::cin >> arr[i].engine.power;

        std::cout << "Engine capacity (liters): ";
        std::cin >> arr[i].engine.volume;
    }
}

void sortVehicles(Vehicle arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].engine.power > arr[j + 1].engine.power) {
                Vehicle temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortFlatVehicles(FlatVehicle arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].power > arr[j + 1].power) {
                FlatVehicle temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printByType(const Vehicle arr[], int size, VehicleType targetType) {
    std::cout << "\nTransport type " << getTypeString(targetType) << " \n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i].type == targetType) {
            std::cout << "Model: " << arr[i].model 
                      << " Power: " << arr[i].engine.power 
                      << " Capacity: " << arr[i].engine.volume << "l\n";
            found = true;
        }
    }
    if (!found) std::cout << "There are no vehicles of this type\n";
}

int main() {
    const int SIZE = 5;
    Vehicle garage[SIZE];

    //inputVehicles(garage, SIZE);
    
    
    garage[0] = {Car, "Toyota Camry", {249, 3.5}};
    garage[1] = {Truck, "Volvo FH", {500, 12.8}};
    garage[2] = {Motorcycle, "Yamaha R1", {200, 1.0}};
    garage[3] = {Car, "Lada Granta", {90, 1.6}};
    garage[4] = {Car, "BMW M5", {600, 4.4}};
    

    std::cout << "\nSorting by power\n";
    sortVehicles(garage, SIZE);

    printByType(garage, SIZE, Car);

    std::cout << "Timing for 100 elements:\n";
    
    const int TEST_SIZE = 100;
    Vehicle structArr[TEST_SIZE];
    FlatVehicle flatArr[TEST_SIZE];

    for (int i = 0; i < TEST_SIZE; ++i) {
        int power = rand() % 500 + 50; 
        
        structArr[i] = {Car, "ModelName", {power, 2.0}};
        flatArr[i] = {"Car", "ModelName", power, 2.0};
    }

    clock_t start1 = clock();
    sortVehicles(structArr, TEST_SIZE);
    clock_t end1 = clock();
    double timeStruct = double(end1 - start1) / CLOCKS_PER_SEC;

    clock_t start2 = clock();
    sortFlatVehicles(flatArr, TEST_SIZE);
    clock_t end2 = clock();
    double timeFlat = double(end2 - start2) / CLOCKS_PER_SEC;

    std::cout << "Sorting time (Struct + Enum): " << std::fixed << timeStruct << " sec.\n";
    std::cout << "Sorting time (Flat + String): " << std::fixed << timeFlat << " sec.\n";

    return 0;
}
