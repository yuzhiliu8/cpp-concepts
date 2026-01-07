#include <iostream>

int accumulate(int x){
    static int s_accumulator{}; //initialized once at the start of the program
    s_accumulator += x;
    return s_accumulator;
}

int main(){

    std::cout << accumulate(4) << "\n";
    std::cout << accumulate(3) << "\n";
    std::cout << accumulate(2) << "\n";
    std::cout << accumulate(1) << "\n";

    return 0;
}

//no way to restart accumulator
// cant have multiple accumulators running
// func isn't exactly reusable (doesn't produce consistent results)