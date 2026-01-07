#include <iostream>
#include <string>

double get_double(){
    double x{};

    std::cout << "Enter a double value: ";
    std::cin >> x;
    return x;
}

int main(){
    double num1{ get_double() };
    double num2{ get_double() };
    double ans{};
    char op{};
    bool op_valid{};

    std::cout << "Enter operator: ";
    std::cin >> op;
    if (op != '+' && op != '-' && op != '*' && op != '/'){
        op_valid = false;
    } else {
        op_valid = true;
    }
    if (op_valid){
        if (op == '+'){
            ans = num1 + num2;
        } else if (op == '-'){
            ans = num1 - num2;
        } else if (op == '*'){
            ans = num1 * num2;
        } else {
            ans = num1 / num2;
        }
        std::cout << num1 << " " << op << " " << num2 << " is " << ans << "\n";
    }

    return 0;
}