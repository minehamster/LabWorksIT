#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Sale{
    std::string date;
    int buyerNumber;
    double amount;
    std::string category;
};

Sale makeSaleFromLine(std::string line){
    Sale sale;

    int firstComma = line.find(",");
    int secondComma = line.find(",", firstComma + 1);
    int thirdComma = line.find(",", secondComma + 1);

    sale.date = line.substr(0, firstComma);

    std::string buyerText = line.substr(firstComma + 1, secondComma - firstComma - 1);
    sale.buyerNumber = std::stoi(buyerText);

    std::string amountText = line.substr(secondComma + 1, thirdComma - secondComma - 1);
    sale.amount = std::stod(amountText);

    sale.category = line.substr(thirdComma + 1);

    return sale;
}

void showSale(Sale sale){
    std::cout << "Date: " << sale.date << std::endl;
    std::cout << "Buyer number: " << sale.buyerNumber << std::endl;
    std::cout << "Amount: " << sale.amount << std::endl;
    std::cout << "Category: " << sale.category << std::endl;
}

std::vector<Sale> readSalesFromFile(std::string fileName){
    std::vector<Sale> sales;
    std::ifstream file(fileName);

    if (!file.is_open()){
        std::cout << "Error: file was not opened for reading" << std::endl;
        return sales;
    }

    std::string line;

    while (std::getline(file, line)){
        if (line.length() > 0){
            Sale sale = makeSaleFromLine(line);
            sales.push_back(sale);
        }
    }

    if (file.bad()){
        std::cout << "Error: problem while reading file" << std::endl;
    }

    file.close();

    return sales;
}

void showAllSales(std::vector<Sale> sales){
    std::cout << "Sales from file:" << std::endl;

    for (int i = 0; i < sales.size(); i++){
        std::cout << "Sale number " << i + 1 << std::endl;
        showSale(sales[i]);
        std::cout << std::endl;
    }
}

void countTotalAmount(std::vector<Sale> sales){
    double totalAmount = 0;

    for (int i = 0; i < sales.size(); i++){
        totalAmount += sales[i].amount;
    }

    std::cout << "Total amount: " << totalAmount << std::endl;
}

void filterSalesByDate(std::vector<Sale> sales, std::string outputFileName){
    std::string date;

    std::cout << "Enter date for filter: ";
    std::cin >> date;

    std::ofstream file(outputFileName);

    if (!file.is_open()){
        std::cout << "Error: file was not opened for writing" << std::endl;
        return;
    }

    int count = 0;

    for (int i = 0; i < sales.size(); i++){
        if (sales[i].date == date){
            file << sales[i].date << ",";
            file << sales[i].buyerNumber << ",";
            file << sales[i].amount << ",";
            file << sales[i].category << std::endl;

            count++;
        }
    }

    if (file.fail()){
        std::cout << "Error: data was not written" << std::endl;
    }
    else{
        std::cout << "Filtered sales were written to file" << std::endl;
        std::cout << "Found sales: " << count << std::endl;
    }

    file.close();
}

int main(){
    std::string inputFileName = "sales.csv";
    std::string outputFileName = "filtered_sales.csv";
    std::vector<Sale> sales = readSalesFromFile(inputFileName);

    if (sales.size() == 0){
        std::cout << "No sales were read" << std::endl;
        return 0;
    }

    int choice = 0;

    while (choice != 4){
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Show all sales" << std::endl;
        std::cout << "2. Count total amount" << std::endl;
        std::cout << "3. Filter sales by date" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        if (choice == 1){
            showAllSales(sales);
        }
        else if (choice == 2){
            countTotalAmount(sales);
        }
        else if (choice == 3){
            filterSalesByDate(sales, outputFileName);
        }
        else if (choice == 4){
            std::cout << "Program finished" << std::endl;
        }
        else{
            std::cout << "Wrong choice" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
