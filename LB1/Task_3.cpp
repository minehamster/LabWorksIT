#include <iostream>
#include <iomanip>
#include <cstdlib>

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

void placeShip(char field[][SIZE], int len, int x, int y, bool horiz){
    bool placed = false;
    while (!placed) {
        if (canPlace(field, x, y, len, horiz)) {
            for (int i = 0; i < len; i++) {
                int r = x + (horiz ? 0 : i);
                int c = y + (horiz ? i : 0);
                field[r][c] = SHIP;
            }
            placed = true;
        }
        else {
            std::cout << "I can't place the ship, change the coordinate and position \n";
            std::cin >> x >> y >> horiz;
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
    bool succ_shot = false;
    while (succ_shot != true){
        if (x < 0 || y < 0 || x > SIZE - 1 || y > SIZE - 1){
            std::cout << "Invalid coordinates, please change ";
            std::cin >> x >> y;
        }
        if (user_field[x][y] == MISS || user_field[x][y] == HIT){
            std::cout << "They've already shot here, plese change coordinates ";
            std::cin >> x >> y;
        }
        if (true_field[x][y] == SHIP){
            system("cls");
            std::cout << "HIT!" << std::endl << "Press Enter to continue";
            std::cin.get();
            std::cin.get();
            user_field[x][y] = HIT;
            true_field[x][y] = HIT;
            succ_shot = true;
        }
        if (true_field[x][y] == EMPTY){
            system("cls");
            std::cout << "MISS!" << std::endl << "Press Enter to continue";
            std::cin.get();
            std::cin.get();
            user_field[x][y] = MISS;
            succ_shot = true;
        }
    }
}

int main(){
    const int len_ships[10] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    int turn = -1;
    char user1_field[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            user1_field[i][j] = EMPTY;
        }
    }

    char user2_field[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            user2_field[i][j] = EMPTY;
        }
    }
    
    char true1_field[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            true1_field[i][j] = EMPTY;
        }
    }

    char true2_field[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            true2_field[i][j] = EMPTY;
        }
    }

    std::cout << "---FIRST PLAYER FIELD--- \n";
    for (int i = 0; i < 10; i++){
        int x, y;
        bool horiz;
        printField(true1_field);
        std::cout << "\nEnter the coordinates (first row, second column) of the ship with lenght " << len_ships[i] << ", as well as whether it is horizontal (true/false): ";
        std::cin >> x >> y >> horiz;
        placeShip(true1_field, len_ships[i], x, y, horiz);
    }
    system("cls");


    std::cout << "---SECOND PLAYER FIELD--- \n";
    for (int i = 0; i < 10; i++){
        int x, y;
        bool horiz;
        printField(true2_field);
        std::cout << "\nEnter the coordinates (first row, second column) of the ship with lenght " << len_ships[i] << ", as well as whether it is horizontal (true/false): ";
        std::cin >> x >> y >> horiz;
        placeShip(true2_field, len_ships[i], x, y, horiz);
        std::cout << std::endl << "Press Enter to continue";
        std::cin.get();
        std::cin.get();
    }
    system("cls");

    while (shipsExist(true1_field) == true && shipsExist(true2_field) == true){
        turn++;
        int x, y;
        if (turn % 2 == 0){
            std::cout << "---FIRST PLAYER TURN---\nYour field: \n";
            printField(true1_field);
            std::cout << "\nField of second player: \n";
            printField(user2_field);
            std::cout << "\nEnter coordinates for the shot (first row, second column): \n";
            std::cin >> x >> y;
            shoot(user2_field, true2_field, x, y);
        }
        else {
            std::cout << "---SECOND PLAYER TURN---\nYour field: \n";
            printField(true2_field);
            std::cout << "\nField of first player: \n";
            printField(user1_field);
            std::cout << "\nEnter coordinates for the shot (first row, second column): \n";
            std::cin >> x >> y;
            shoot(user1_field, true1_field, x, y);
        }
        if (shipsExist(true1_field) == false){
            std::cout << "\n---SECOND PLAYER WON!---\n";
            return 1;
        }
        else if (true2_field == false) {
            std::cout << "\n---FIRST PLAYER WON!---\n";
            return 1;
        }
    }
    return 0;

}