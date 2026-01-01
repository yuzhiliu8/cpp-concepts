#include <iostream>

void example1(){
    int x{};
    std::cin >> x;
    int y{};
    std::cin >> y;
    std::cout << x << " " << y << "\n";
}

int main(){
    // example1();
    // return 0;
    int x{};
    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << x * 2 << "\n";
}
/*
Example 1 runs:

Run 1:
4       <-- input
5       <-- input 
4 5

1. 4 is in the buffer, gets removed and assigned to x
3. 5 added to buffer, gets removed and assigned to y
5. x and y print statement

Run 2:
4 5     <-- input
4 5

1. 4 5 are both added to buffer
2. 4 removed from buffer, assigned to x;
4. 5 removed from buffer, assigned to y;
6. x and y print statement

Run 3:
4 5t <-- input
4 5

1. t is still left in the input buffer after this
*/
