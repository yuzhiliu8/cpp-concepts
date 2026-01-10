#include <iostream>

int calculate(int x, int y, char op){
    switch (op){
    case '+':
        return x + y; 
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        std::cout << "Operator not valid! returning -1..";
        return -1;
    }
}

int main(){
    int x{};
    int y{};
    std::cin >> x >> y;

    char op{};
    std::cin >> op;

    std::cout << calculate(x, y, op) << "\n";
    return 0;
}