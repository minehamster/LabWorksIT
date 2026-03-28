#include <iostream>
#include <iomanip>

int main(){
    int n, m, num = 1, max = -1;
    std::cout << "Enter matrix size (m and n): ";
    std::cin >> m >> n;
    if (n <= 0 || m <= 0){
        std::cout << "Invalid numbers";
        return -1;
    }

    int **matrix = new int*[m];
    for (int i = 0; i < m; i++){
        matrix[i] = new int[n];
    }

    std::cout << "Matrix elements and sums of values in rows and columns: ";
    for (int i = 0; i < m; i++){
        int sum_row = 0;
        std::cout << std::endl;

        for (int j = 0; j < n; j++){
            matrix[i][j] = num++;
            std::cout << std::setw(9) << matrix[i][j];

            sum_row += matrix[i][j];
            if (j == n-1){
                std::cout << "; " << "Sum: " << sum_row;
            }
        }
    }

    std::cout << std::endl;

    for (int j = 0; j < n; j++){
        int sum_cols = 0;
        for (int i = 0; i < m; i++){
            sum_cols += matrix[i][j];
        }
        std::cout << " " << "Sum: " << sum_cols;
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (max < matrix[i][j]){
                max = matrix[i][j];
            }
        }
    }
    std::cout << std::endl << "Maximum matrix element: " << max << std::endl;

    int **transposed = new int*[n];
    for (int j = 0; j < n; j++){
        transposed[j] = new int[m];
    }

    std::cout << "Transposed matrix: ";
    for (int j = 0; j < n; j++){
        std::cout << std::endl;
        for (int i = 0; i < m; i++){
            transposed[j][i] = matrix[i][j];
            std::cout << std::setw(9) << transposed[j][i];
        }
    }

    for (int i = 0; i < m; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int j = 0; j < n; j++){
        delete[] transposed[j];
    }
    delete[] transposed;

    return 0;
}