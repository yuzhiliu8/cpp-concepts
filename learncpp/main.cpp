#include <iostream>
#include "test.hpp"

int f();

int main(){
    int arr[5];
    arr[0] = 3;
    int* a = &arr[0];
    *a = 1;
    std::cout << *a << "\n";
    std::cout << arr[0] << "\n";
    // add(3, 4);
    f();

    return 0;
}