#include <iostream>

int main(){
    float initial_height{};
    std::cout << "Enter height of tower: ";
    std::cin >> initial_height;
    float ball_height{ initial_height };
    float acceleration{ 9.8 };

    for (int i = 0; i <= 5; i++){
        ball_height = initial_height - (0.5 * acceleration * i * i);
        if (ball_height <= 0.0f){
        std::cout << "At " << i << " seconds, the ball is on the ground.\n";
        } else {
            std::cout << "At " << i << " seconds, the ball is at height " << ball_height << "\n";
        }
    }
    return 0;
}