#include "io.hpp"
#include <iostream>

int read_number(){
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

void write_answer(int x){
    std::cout << "Answer: " << x << "\n";
}