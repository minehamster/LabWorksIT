#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string text = "Programming is fun. C++ is powerful. Programming requires practice.";

    std::cout << "Text: " << text << std::endl;

    int charactersWithoutSpaces = 0;

    for (int i = 0; i < text.length(); i++){
        if (text[i] != ' '){
            charactersWithoutSpaces++;
        }
    }

    std::cout << "Characters without spaces: " << charactersWithoutSpaces << std::endl;

    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; i < text.length(); i++){
        if (text[i] != ' ' && inWord == false){
            wordCount++;
            inWord = true;
        }
        else if (text[i] == ' '){
            inWord = false;
        }
    }

    std::cout << "Words count: " << wordCount << std::endl;

    int sentenceCount = 0;

    for (int i = 0; i < text.length(); i++){
        if (text[i] == '.'){
            sentenceCount++;
        }
    }

    std::cout << "Sentences count: " << sentenceCount << std::endl;

    int isCount = 0;
    std::size_t position = text.find("is");

    while (position != std::string::npos){
        isCount++;
        position = text.find("is", position + 1);
    }

    std::cout << "Word is count: " << isCount << std::endl;

    std::string upperText = text;

    for (int i = 0; i < upperText.length(); i++){
        upperText[i] = std::toupper(upperText[i]);
    }

    std::cout << "First 20 characters in upper case: ";
    std::cout << upperText.substr(0, 20) << std::endl;

    std::string newText = text;

    for (int i = 0; i < newText.length(); i++){
        if (newText[i] == '.'){
            newText[i] = '!';
        }
    }

    std::cout << "Text with exclamation marks: " << newText << std::endl;

    return 0;
}
