#include <iostream>

int main(){
    int n, sum = 0, max = -1, sr;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    if (n <= 0){
        std::cout << "Invalid number";
        return -1;
    }
    int *array = new int[n];
    for (int i = 0; i < n; i++){
        array[i] = i*i;
        if (i==0){
            std::cout << "Array elements: ";
        }
        std::cout << array[i] << " ";
        sum += i*i;
    }

    for (int i = 0; i < n; i++){
        if (array[i] > max){
            max = array[i];
        }
    }
    sr = sum / n;

    std::cout << std::endl << "Sum of array elements: " << sum << std::endl;
    std::cout << "Arithmetic mean of array elements: " << sr << std::endl;
    std::cout << "Maximum array element: " << max << std::endl;
    delete[] array;
    return 0;
}
