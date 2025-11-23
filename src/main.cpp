#include <iostream>
#include <vector>
#include "deque.hpp"

int* ptr_test(){
    int* value = new int(5);
    std::cout << *value << std::endl;
    return value;
}

int main(){
    
    int* ptr = ptr_test();
    std::cout << "Pointer: " << std::endl;
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;
    std::cout << "value: " << std::endl;
    std::cout << *ptr << std::endl;
    return 0;
}
