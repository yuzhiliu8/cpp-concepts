#include <iostream>

void fizzbuzz(int x){
    for (int i = 1; i <= x; ++i){
        if (i % 3 == 0){
            std::cout << "fizz";
        }
        if (i % 5 == 0){
            std::cout << "buzz";
        }
        if (i % 7 == 0){
            std::cout << "pop";
        }
        if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0){
            std::cout << i;
        }
        std::cout << "\n";
    }

}

int main(){
    fizzbuzz(150);

    // char c{'a'};
    // while (c <= 'z'){
    //     std::cout << c << " ";
    //     ++c;
    // }
    // std::cout << "\n\n";

    // int start{5};
    // while (start >= 1){
    //     int c{start};
    //     while (c >= 1){
    //         std::cout << c << " ";
    //         --c;
    //     }
    //     std::cout << "\n";
    //     --start;
    // }

    // std::cout << "\n\n";

    // start = 1;
    // int end{9};
    // while (start <= end){
    //     int curr{end};
    //     while (curr >= 1){
    //         if (curr <= start){
    //             std::cout << curr << " ";
    //         } else {
    //             std::cout << "  ";
    //         }
    //         // std::cout << curr << " ";
    //         --curr;
    //     }
    //     std::cout << "\n";
    //     ++start;
    // }


    return 0;
}