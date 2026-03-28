#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const int SIZE = 10;
const char SHIP = 'S';
const char EMPTY = '~';
const char HIT = 'X';
const char MISS = 'M'; 

void printField(char field[SIZE][SIZE]){
    std::cout << std::endl << "  ";
    for (int i = 0; i < SIZE; i++){
        std::cout << std::setw(2) << i;
    }

    for (int i = 0; i < SIZE; i++){
        std::cout << std::endl << std::setw(2) << i;
        for (int j = 0; j < SIZE; j++){
            std::cout << std::setw(2) << field[i][j];
        }
    }
}

bool canPlace(char field[][SIZE], int row, int col, int len, int horiz){
    for (int i = 0; i < len; i++){
        int r = row + (horiz ? 0 : i);
        int c = col + (horiz ? i : 0);
        
        if (r >= SIZE || c >= SIZE || field[r][c] != EMPTY) {
            return false;
        }
        
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && field[nr][nc] == SHIP) {
                    return false;
                }
            }
        }
    }
    return true;
}

void placeShip(char field[][SIZE], int len){
    bool placed = false;
    while (!placed) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        bool horiz = rand() % 2 == 0;
        
        if (canPlace(field, row, col, len, horiz)) {
            for (int i = 0; i < len; i++) {
                int r = row + (horiz ? 0 : i);
                int c = col + (horiz ? i : 0);
                field[r][c] = SHIP;
            }
            placed = true;
        }
    }
}

bool shipsExist(char field[][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (field[i][j] == SHIP){
                return true;
            }
        }
    }
    return false;
}

void shoot(char user_field[][SIZE], char true_field[][SIZE], int x, int y){
    if (x < 0 || y < 0 || x > SIZE - 1 || y > SIZE - 1){
        std::cout << "Invalid coordinates" << std::endl;
        return;
    }
    if (user_field[x][y] == MISS || user_field[x][y] == HIT){
        std::cout << "They've already shot here" << std::endl;
        return;
    }
    if (true_field[x][y] == SHIP){
        std::cout << "HIT!" << std::endl;
        user_field[x][y] = HIT;
        true_field[x][y] = HIT;
        return;
    }
    if (true_field[x][y] == EMPTY){
        std::cout << "MISS!" << std::endl;
        user_field[x][y] = MISS;
        return;
    } 

}

int main(){
    std::srand(std::time(0));
    char user_field[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            user_field[i][j] = EMPTY;
        }
    }
    
    char true_field[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            true_field[i][j] = EMPTY;
        }
    }
    placeShip(true_field, 4);
    placeShip(true_field, 3);
    placeShip(true_field, 3);
    placeShip(true_field, 2);
    placeShip(true_field, 2);
    placeShip(true_field, 2);
    placeShip(true_field, 1);
    placeShip(true_field, 1);
    placeShip(true_field, 1);
    placeShip(true_field, 1);

    printField(user_field);
    while (shipsExist(true_field) == true){
        int x,y;
        std::cout << std::endl << "Enter coordinates for the shot (first row, second column): " << std::endl;
        std::cin >> x >> y;
        shoot(user_field, true_field, x, y);
        printField(user_field);
    }
    std::cout << "\n ---YOU WIN!--- \n";
    return 0;

}