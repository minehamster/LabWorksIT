#include <iostream>
#include <fstream>
#include <cstring>

struct Product{
    int code;
    char name[50];
    double price;
    int count;
};

void addProductToFile(std::string fileName){
    Product product;

    std::cout << "Enter product code: ";
    std::cin >> product.code;

    std::cin.ignore();

    std::cout << "Enter product name: ";
    std::cin.getline(product.name, 50);

    std::cout << "Enter product price: ";
    std::cin >> product.price;

    std::cout << "Enter product count: ";
    std::cin >> product.count;

    std::ofstream file(fileName, std::ios::binary | std::ios::app);

    if (!file.is_open()){
        std::cout << "Error: file was not opened for writing" << std::endl;
        return;
    }

    file.write((char*)&product, sizeof(Product));

    if (file.fail()){
        std::cout << "Error: product was not written" << std::endl;
    }
    else{
        std::cout << "Product was added to file" << std::endl;
    }

    file.close();
}

void showProduct(Product product){
    std::cout << "Code: " << product.code << std::endl;
    std::cout << "Name: " << product.name << std::endl;
    std::cout << "Price: " << product.price << std::endl;
    std::cout << "Count: " << product.count << std::endl;
}

void readProductsFromFile(std::string fileName){
    Product product;

    std::ifstream file(fileName, std::ios::binary);

    if (!file.is_open()){
        std::cout << "Error: file was not opened for reading" << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "Products from file:" << std::endl;

    while (file.read((char*)&product, sizeof(Product))){
        showProduct(product);
        std::cout << std::endl;
    }

    if (file.bad()){
        std::cout << "Error: problem while reading file" << std::endl;
    }

    file.close();
}

void findProductByCode(std::string fileName)
{
    Product product;
    int code;
    bool found = false;

    std::cout << "Enter code to find: ";
    std::cin >> code;

    std::ifstream file(fileName, std::ios::binary);

    if (!file.is_open()){
        std::cout << "Error: file was not opened for reading" << std::endl;
        return;
    }

    while (file.read((char*)&product, sizeof(Product))){
        if (product.code == code){
            std::cout << "Product was found:" << std::endl;
            showProduct(product);
            found = true;
        }
    }

    if (found == false){
        std::cout << "Product was not found" << std::endl;
    }

    if (file.bad()){
        std::cout << "Error: problem while reading file" << std::endl;
    }

    file.close();
}

void countTotalPrice(std::string fileName){
    Product product;
    double totalPrice = 0;

    std::ifstream file(fileName, std::ios::binary);

    if (!file.is_open()){
        std::cout << "Error: file was not opened for reading" << std::endl;
        return;
    }

    while (file.read((char*)&product, sizeof(Product))){
        totalPrice += product.price * product.count;
    }

    if (file.bad()){
        std::cout << "Error: problem while reading file" << std::endl;
    }
    else{
        std::cout << "Total price of all products: " << totalPrice << std::endl;
    }

    file.close();
}

int main(){
    std::string fileName = "products.bin";

    int choice = 0;

    while (choice != 5){
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add product" << std::endl;
        std::cout << "2. Show all products" << std::endl;
        std::cout << "3. Find product by code" << std::endl;
        std::cout << "4. Count total price" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1){
            addProductToFile(fileName);
        }
        else if (choice == 2){
            readProductsFromFile(fileName);
        }
        else if (choice == 3){
            findProductByCode(fileName);
        }
        else if (choice == 4){
            countTotalPrice(fileName);
        }
        else if (choice == 5){
            std::cout << "Program finished" << std::endl;
        }
        else{
            std::cout << "Wrong choice" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
