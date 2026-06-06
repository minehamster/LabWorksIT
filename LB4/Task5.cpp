#include <iostream>
#include <string>
#include <vector>
#include <cctype>

bool isPhoneValid(std::string phone, std::string& digitsOnly){
    digitsOnly = "";

    if (phone.length() == 0){
        return false;
    }

    if (phone[0] != '+' && !std::isdigit(phone[0])){
        return false;
    }

    for (int i = 0; i < phone.length(); i++){
        if (std::isdigit(phone[i])){
            digitsOnly += phone[i];
        }
        else if (phone[i] == '+' || phone[i] == '-' || phone[i] == ' ' || phone[i] == '(' || phone[i] == ')'){
        }
        else{
            return false;
        }
    }

    if (digitsOnly.length() < 10 || digitsOnly.length() > 11){
        return false;
    }

    return true;
}

std::string makeFormat(std::string digitsOnly){
    if (digitsOnly.length() == 10){
        digitsOnly = "7" + digitsOnly;
    }

    std::string result = "";

    result += "+";
    result += digitsOnly[0];

    result += " (";
    result += digitsOnly.substr(1, 3);
    result += ") ";

    result += digitsOnly.substr(4, 3);
    result += "-";

    result += digitsOnly.substr(7, 2);
    result += "-";

    result += digitsOnly.substr(9, 2);

    return result;
}

int main(){
    std::vector<std::string> phones;

    phones.push_back("+7 (999) 123-45-67");
    phones.push_back("8-999-123-45-67");
    phones.push_back("+1 212 456-7890");
    phones.push_back("999-123-45-67");
    phones.push_back("+7999123456789");
    phones.push_back("123456789");

    int validCount = 0;
    int invalidCount = 0;

    for (int i = 0; i < phones.size(); i++){
        std::string digitsOnly = "";

        std::cout << "Phone: " << phones[i] << std::endl;

        if (isPhoneValid(phones[i], digitsOnly)){
            validCount++;

            std::cout << "Status: valid" << std::endl;
            std::cout << "Digits only: " << digitsOnly << std::endl;
            std::cout << "New format: " << makeFormat(digitsOnly) << std::endl;
        }
        else{
            invalidCount++;

            std::cout << "Status: invalid" << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "Valid phones: " << validCount << std::endl;
    std::cout << "Invalid phones: " << invalidCount << std::endl;

    return 0;
}
