#include <iostream>
#include <string>

enum Day {
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7,
};

struct Weather {
    Day day;
    int temperature;
    bool rainfall;
};

std::string dayToString(Day d) {
    switch(d) {
        case Monday: return "Monday";
        case Tuesday: return "Tuesday";
        case Wednesday: return "Wednesday";
        case Thursday: return "Thursday";
        case Friday: return "Friday";
        case Saturday: return "Saturday";
        case Sunday: return "Sunday";
        default: return "Unknown";
    }
}

void findWarm(Weather week[], int size) {
    int max_temp = -300;
    Weather warm_day = week[0]; 
    
    for (int i = 0; i < size; i++) {
        if (week[i].temperature > max_temp) {
            max_temp = week[i].temperature;
            warm_day = week[i];
        }
    }
    std::cout << "The warmest day (using structs) is " << dayToString(warm_day.day) 
              << ", Temp: " << warm_day.temperature << "\n";
}

void findWarmArrays(std::string days[], int temps[], bool rainfall[], int size) {
    int max_temp = -300;
    std::string warm_day = days[0];

    for (int i = 0; i < size; ++i) {
        if (temps[i] > max_temp) {
            max_temp = temps[i];
            warm_day = days[i];
        }
    }
    std::cout << "The warmest day (using arrays) is " << warm_day 
              << ", Temp: " << max_temp << "\n";
}

int main() {
    Weather week[7] = {
        {Monday, 12, true},
        {Tuesday, 13, false},
        {Wednesday, 16, false},
        {Thursday, 15, false},
        {Friday, 14, true},
        {Saturday, 11, true},
        {Sunday, 18, false}
    };
    
    findWarm(week, 7);

    std::string daysArr[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int tempsArr[7] = {12, 13, 16, 15, 14, 11, 18};
    bool rainArr[7] = {true, false, false, false, true, true, false};

    findWarmArrays(daysArr, tempsArr, rainArr, 7);

    return 0;
}
