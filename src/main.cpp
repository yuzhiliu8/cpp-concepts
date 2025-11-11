#include <iostream>
#include "deque.hpp"

int main(){

    Deque d({1, 2, 3, 4, 50, 55});

    std::cout << d.toString() << std::endl;
    return 0;
}
