#include <iostream>

int main(){
    int n, max = -1;
    float sum = 0;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    if (n <= 0){
        std::cout << "Invalid number";
        return -1;
    }
    std::cout << "Array elements: ";
    int *array = new int[n];
    for (int i = 0; i < n; i++){
        array[i] = i*i;
        std::cout << array[i] << " ";
        sum += array[i];
    }

    for (int i = 0; i < n; i++){
        if (array[i] > max){
            max = array[i];
        }
    }
    float sr = sum / n;

    std::cout << std::endl << "Sum of array elements: " << sum << std::endl;
    std::cout << "Arithmetic mean of array elements: " << sr << std::endl;
    std::cout << "Maximum array element: " << max << std::endl;
    delete[] array;
    return 0;
}
