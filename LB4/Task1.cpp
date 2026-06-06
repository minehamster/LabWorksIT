#include <iostream>
#include <string>
#include <cstring>

int main()
{
    const char* firstString = "Hello";
    std::string secondString = "World";

    std::cout << "First string: " << firstString << std::endl;
    std::cout << "Second string: " << secondString << std::endl;

    std::cout << "Length of first string: " << std::strlen(firstString) << std::endl;
    std::cout << "Length of second string: " << secondString.length() << std::endl;

    std::string firstStringAsStd = firstString;
    std::string joinedString = firstStringAsStd + " " + secondString;

    std::cout << "Joined string: " << joinedString << std::endl;

    if (firstString == secondString){
        std::cout << "Strings are equal" << std::endl;
    }
    else{
        std::cout << "Strings are not equal" << std::endl;
    }

    return 0;
}
