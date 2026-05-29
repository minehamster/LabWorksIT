#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <chrono>

const int WORD_COUNT = 60;

bool startsWithA(const std::string& word)
{
    return word.length() > 0 && word[0] == 'A';
}

bool isVowel(char letter)
{
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
           letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U';
}

char replaceVowelLetter(char letter)
{
    if (isVowel(letter))
    {
        return '*';
    }

    return letter;
}

std::string replaceVowelsInWord(std::string word)
{
    std::transform(word.begin(), word.end(), word.begin(), replaceVowelLetter);

    return word;
}

bool isShorter(const std::string& first, const std::string& second)
{
    return first.length() < second.length();
}

bool isLongWord(const std::string& word)
{
    return word.length() > 7;
}

void printVectorWords(const std::vector<std::string>& words)
{
    for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

void printFirstFiveArray(const std::array<std::string, WORD_COUNT>& words)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << words[i] << " ";
    }

    std::cout << std::endl;
}

void printFirstFiveVector(const std::vector<std::string>& words)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << words[i] << " ";
    }

    std::cout << std::endl;
}

void printFirstFiveList(const std::list<std::string>& words)
{
    std::list<std::string>::const_iterator it = words.begin();

    for (int i = 0; i < 5; i++)
    {
        std::cout << *it << " ";
        it++;
    }

    std::cout << std::endl;
}

std::vector<std::string> findAWordsInArray(std::array<std::string, WORD_COUNT>& words)
{
    std::vector<std::string> result;

    std::array<std::string, WORD_COUNT>::iterator it = words.begin();

    while (it != words.end())
    {
        it = std::find_if(it, words.end(), startsWithA);

        if (it != words.end())
        {
            result.push_back(*it);
            it++;
        }
    }

    return result;
}

std::vector<std::string> findAWordsInVector(std::vector<std::string>& words)
{
    std::vector<std::string> result;

    std::vector<std::string>::iterator it = words.begin();

    while (it != words.end())
    {
        it = std::find_if(it, words.end(), startsWithA);

        if (it != words.end())
        {
            result.push_back(*it);
            it++;
        }
    }

    return result;
}

std::vector<std::string> findAWordsInList(std::list<std::string>& words)
{
    std::vector<std::string> result;

    std::list<std::string>::iterator it = words.begin();

    while (it != words.end())
    {
        it = std::find_if(it, words.end(), startsWithA);

        if (it != words.end())
        {
            result.push_back(*it);
            it++;
        }
    }

    return result;
}

void replaceVowelsInArray(std::array<std::string, WORD_COUNT>& words)
{
    std::transform(words.begin(), words.end(), words.begin(), replaceVowelsInWord);
}

void replaceVowelsInVector(std::vector<std::string>& words)
{
    std::transform(words.begin(), words.end(), words.begin(), replaceVowelsInWord);
}

void replaceVowelsInList(std::list<std::string>& words)
{
    std::transform(words.begin(), words.end(), words.begin(), replaceVowelsInWord);
}

std::string findLongestWordInArray(std::array<std::string, WORD_COUNT>& words)
{
    std::array<std::string, WORD_COUNT>::iterator it;

    it = std::max_element(words.begin(), words.end(), isShorter);

    return *it;
}

std::string findLongestWordInVector(std::vector<std::string>& words)
{
    std::vector<std::string>::iterator it;

    it = std::max_element(words.begin(), words.end(), isShorter);

    return *it;
}

std::string findLongestWordInList(std::list<std::string>& words)
{
    std::list<std::string>::iterator it;

    it = std::max_element(words.begin(), words.end(), isShorter);

    return *it;
}

std::vector<std::string> filterLongWordsFromArray(std::array<std::string, WORD_COUNT>& words)
{
    std::vector<std::string> result;

    std::copy_if(words.begin(), words.end(), std::back_inserter(result), isLongWord);

    return result;
}

std::vector<std::string> filterLongWordsFromVector(std::vector<std::string>& words)
{
    std::vector<std::string> result;

    std::copy_if(words.begin(), words.end(), std::back_inserter(result), isLongWord);

    return result;
}

std::list<std::string> filterLongWordsFromList(std::list<std::string>& words)
{
    std::list<std::string> result;

    std::copy_if(words.begin(), words.end(), std::back_inserter(result), isLongWord);

    return result;
}

int main()
{
    std::array<std::string, WORD_COUNT> arrayWords = {
        "Apple", "Ant", "Airplane", "Artist", "Anchor",
        "Animal", "Autumn", "Academy", "Adventure", "Alphabet",
        "Banana", "Orange", "Window", "Computer", "Garden",
        "River", "Mountain", "Library", "Pencil", "Notebook",
        "School", "Teacher", "Student", "City", "Village",
        "Planet", "Galaxy", "Rocket", "Ocean", "Forest",
        "Camera", "Bottle", "Chair", "Table", "Keyboard",
        "Monitor", "Phone", "Sandwich", "Chocolate", "Dolphin",
        "Elephant", "Tiger", "Lion", "Zebra", "Guitar",
        "Violin", "Picture", "History", "Science", "Language",
        "Browser", "Internet", "Airport", "Apartment", "Engine",
        "Bicycle", "Baseball", "Football", "Rainbow", "Flower"
    };

    std::vector<std::string> vectorWords(arrayWords.begin(), arrayWords.end());
    std::list<std::string> listWords(arrayWords.begin(), arrayWords.end());

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point finish;

    std::cout << "Array container" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> arrayAWords = findAWordsInArray(arrayWords);
    finish = std::chrono::high_resolution_clock::now();

    long long arrayFindTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    replaceVowelsInArray(arrayWords);
    finish = std::chrono::high_resolution_clock::now();

    long long arrayTransformTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    std::string arrayLongestWord = findLongestWordInArray(arrayWords);
    finish = std::chrono::high_resolution_clock::now();

    long long arrayMaxTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> arrayLongWords = filterLongWordsFromArray(arrayWords);
    finish = std::chrono::high_resolution_clock::now();

    long long arrayCopyTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Words starting with A: ";
    printVectorWords(arrayAWords);
    std::cout << "First 5 words after replacing vowels: ";
    printFirstFiveArray(arrayWords);
    std::cout << "Longest word: " << arrayLongestWord << std::endl;
    std::cout << "Words longer than 7 letters: " << arrayLongWords.size() << std::endl;
    std::cout << "Find time: " << arrayFindTime << " ns" << std::endl;
    std::cout << "Transform time: " << arrayTransformTime << " ns" << std::endl;
    std::cout << "Max element time: " << arrayMaxTime << " ns" << std::endl;
    std::cout << "Copy if time: " << arrayCopyTime << " ns" << std::endl;

    std::cout << std::endl;

    std::cout << "Vector container" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> vectorAWords = findAWordsInVector(vectorWords);
    finish = std::chrono::high_resolution_clock::now();

    long long vectorFindTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    replaceVowelsInVector(vectorWords);
    finish = std::chrono::high_resolution_clock::now();

    long long vectorTransformTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    std::string vectorLongestWord = findLongestWordInVector(vectorWords);
    finish = std::chrono::high_resolution_clock::now();

    long long vectorMaxTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> vectorLongWords = filterLongWordsFromVector(vectorWords);
    finish = std::chrono::high_resolution_clock::now();

    long long vectorCopyTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Words starting with A: ";
    printVectorWords(vectorAWords);
    std::cout << "First 5 words after replacing vowels: ";
    printFirstFiveVector(vectorWords);
    std::cout << "Longest word: " << vectorLongestWord << std::endl;
    std::cout << "Words longer than 7 letters: " << vectorLongWords.size() << std::endl;
    std::cout << "Find time: " << vectorFindTime << " ns" << std::endl;
    std::cout << "Transform time: " << vectorTransformTime << " ns" << std::endl;
    std::cout << "Max element time: " << vectorMaxTime << " ns" << std::endl;
    std::cout << "Copy if time: " << vectorCopyTime << " ns" << std::endl;

    std::cout << std::endl;

    std::cout << "List container" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> listAWords = findAWordsInList(listWords);
    finish = std::chrono::high_resolution_clock::now();

    long long listFindTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    replaceVowelsInList(listWords);
    finish = std::chrono::high_resolution_clock::now();

    long long listTransformTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    std::string listLongestWord = findLongestWordInList(listWords);
    finish = std::chrono::high_resolution_clock::now();

    long long listMaxTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    start = std::chrono::high_resolution_clock::now();
    std::list<std::string> listLongWords = filterLongWordsFromList(listWords);
    finish = std::chrono::high_resolution_clock::now();

    long long listCopyTime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

    std::cout << "Words starting with A: ";
    printVectorWords(listAWords);
    std::cout << "First 5 words after replacing vowels: ";
    printFirstFiveList(listWords);
    std::cout << "Longest word: " << listLongestWord << std::endl;
    std::cout << "Words longer than 7 letters: " << listLongWords.size() << std::endl;
    std::cout << "Find time: " << listFindTime << " ns" << std::endl;
    std::cout << "Transform time: " << listTransformTime << " ns" << std::endl;
    std::cout << "Max element time: " << listMaxTime << " ns" << std::endl;
    std::cout << "Copy if time: " << listCopyTime << " ns" << std::endl;

    std::cout << std::endl;

    return 0;
}
