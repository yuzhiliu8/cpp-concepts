#include <iostream>

int main(){
    int small{};
    int large{};
    std::cout << "enter a number: ";
    std::cin >> small;
    std::cout << "enter a larger number: ";
    std::cin >> large;

    if (large < small)
    {
        int temp = small;
        small = large;
        large = temp;
    }   //temp dies here

    std::cout << "Smaller: " << small << "\n";
    std::cout << "Bigger: " << large << "\n";



    
    return 0;
} //small, large dies