#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
};

void printBooks(Book array[], int size) {
    for(int i = 0; i < size; i++){
        std::cout << i + 1 << ") " << array[i].title << ", " << array[i].author << ", " << array[i].year << "\n";
    }
}

void findBooks(Book array[], int size) {
    bool succ_search = false;
    std::string author;
    std::cout << "\nEnter the author's name to search: ";
    std::getline(std::cin, author);
    for (int i = 0; i < size; i++){
        if (array[i].author == author){
            std::cout << array[i].title << ", " << array[i].year << "\n";   
            succ_search = true;
        }
    }
    if (succ_search == false){
        std::cout << "There is no such author\n";
    }
}

struct Library
{
    Book books[5];
};


int main() {
    Book books_array[5] = {
        {"Raising the bar", "Valve", 2004},
        {"For Whom the Bell Tolls", "Ernest Hemingway", 1941},
        {"The Master and Margarita", "Mikhail Bulgakov", 1967},
        {"War and Peace", "Leo Tolstoy", 1869},
        {"Crime and Punishment", "Fyodor Dostoevsky", 1866}
    };

    Library my_library = {
        {
            {"Raising the bar", "Valve", 2004},
            {"For Whom the Bell Tolls", "Ernest Hemingway", 1941},
            {"The Master and Margarita", "Mikhail Bulgakov", 1967},
            {"War and Peace", "Leo Tolstoy", 1869},
            {"Crime and Punishment", "Fyodor Dostoevsky", 1866}
        }   
    };
    printBooks(books_array, 5);
    findBooks(books_array, 5);

    std::cout << "\nExample of acces via Books\n" << "The first book was published in " << books_array[0].year << "\n";
    std::cout << "\nExample of acces via Library\n" << "The second book was published in " << my_library.books[1].year << "\n";

    return 0;
}