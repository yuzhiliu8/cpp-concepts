#include <iostream>
#include <memory>
#include <string>

//We want to be able to write this max function for many types, such as int, double, float, etc, etc
//For all of these param types, the logic is exactly the same, so we use function templates instead
// A way for the compiler to generate all of these overloaded methods w/o us needing to write them

// int max(int x, int y) {
//     std::cout << "hello\n";
//     return (x > y) ? x : y;
// }
//
// Instead, use a single function template
template <typename T> //name of the type parameter is T
T max(T x, T y) {
    return (x > y) ? x : y;
}
// This method will work for all types overloaded comparison operators, although it may work
// with unintuitive behavior for some types. No semantic sense
// Based on what is in the src code, those overloaded will get compiled and executed
// similar to Func overloading, we can disallow some template type params to get compiled
//
template<>
std::string max(std::string x, std::string y) = delete;


//Non type template parameters
template<int x>
void foo() {
    for (int i = 0; i < x; ++i) {
        std::cout << "do smth " << x << "\n";
    }
}

int main() {
    std::cout << max<int>(1, 2) << "\n";
    std::cout << max<double>(1, 2) << "\n";
    std::cout << max<float>(1, 2) << "\n";
    std::cout << max<short>(1, 2) << "\n";
    //std::cout << max<std::string>("hello", "hi") << "\n"; //compile error
    constexpr int x = 5;
    for (int i = 0; i < 5; ++i) {
        foo<x>();
    }


    return 0;
}

