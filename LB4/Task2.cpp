#include <iostream>
#include <string>

int main()
{
    std::string text = "The quick brown fox jumps over the lazy dog";
    std::cout << "Text: " << text << std::endl;
    std::size_t foxPosition = text.find("fox");

    if (foxPosition != std::string::npos){
        std::cout << "First position of fox: " << foxPosition << std::endl;
    }
    else{
        std::cout << "Fox was not found" << std::endl;
    }

    std::size_t catPosition = text.find("cat");

    if (catPosition != std::string::npos){
        std::cout << "String contains cat: yes" << std::endl;
    }
    else{
        std::cout << "String contains cat: no" << std::endl;
    }

    std::string changedText = text;

    std::size_t quickPosition = changedText.find("quick");

    if (quickPosition != std::string::npos){
        changedText.replace(quickPosition, 5, "slow");
    }

    std::cout << "After replacing quick with slow: " << changedText << std::endl;

    for (int i = 0; i < changedText.length(); i++){
        if (changedText[i] == 'o'){
            changedText[i] = '0';
        }
    }

    std::cout << "After replacing o with 0: " << changedText << std::endl;
    std::string part = text.substr(3, 5);
    std::cout << "Substring from 4th to 8th character: " << part << std::endl;

    return 0;
}
