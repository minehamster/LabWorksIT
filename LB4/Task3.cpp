#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string text;
    std::vector<std::string> words;

    std::cout << "Enter words separated by commas: ";
    std::getline(std::cin, text);

    std::string currentWord = "";

    for (int i = 0; i < text.length(); i++){
        if (text[i] == ','){
            words.push_back(currentWord);
            currentWord = "";
        }
        else{
            currentWord += text[i];
        }
    }

    words.push_back(currentWord);

    std::cout << "Number of elements: " << words.size() << std::endl;

    std::cout << "Elements:" << std::endl;

    for (int i = 0; i < words.size(); i++){
        std::cout << i + 1 << ". " << words[i] << std::endl;
    }

    std::string longestWord = "";

    for (int i = 0; i < words.size(); i++){
        if (words[i].length() > longestWord.length()){
            longestWord = words[i];
        }
    }

    std::cout << "Longest word: " << longestWord << std::endl;

    std::string joinedText = "";

    for (int i = 0; i < words.size(); i++){
        joinedText += words[i];

        if (i != words.size() - 1){
            joinedText += " | ";
        }
    }

    std::cout << "Joined text: " << joinedText << std::endl;

    return 0;
}
