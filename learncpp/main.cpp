#include <iostream>
#include "test.hpp"
#include <string>
#include <string_view>

int f();

int main(){
    // int arr[5];
    // arr[0] = 3;
    // int* a = &arr[0];
    // *a = 1;
    // std::cout << *a << "\n";
    // std::cout << arr[0] << "\n";
    // // add(3, 4);
    // f();

    // int x { 2'147'483'647 };
    // std::cout << x + 1 << "\n"; //overflow, -2147483648
    std::string_view sv { "hello "};
    std::string s { sv };

    std::cout << s << "\n";

    return 0;
}