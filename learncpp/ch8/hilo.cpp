#include <iostream>
#include <random>
#include <chrono>

namespace Random {

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rg{seed};

    int get(int min, int max){ //inclusive
        return std::uniform_int_distribution<int>{min, max}(rg);
    }
}

void hilo(){
    std::cout << "Random Number 1-100. You have 7 guesses.\n";
    int random_number{Random::get(1, 100)};
    unsigned int current_guess{};
    bool playing{true};
    int guess_attempts{};
    while (playing){
        ++guess_attempts;
        std::cout << "Guess #" << guess_attempts << ": ";
        int current_guess{};
        std::cin >> current_guess;

        if (current_guess == random_number){
            std::cout << "Correct! You have won!\n";
            playing = false;
        } else if (guess_attempts == 7){
            std::cout << "You failed in 7 guesses! The correct number was: " << random_number << "\n";
            playing = false;
        } else if (current_guess > random_number){
            std::cout << "Guess lower!\n";

        } else if (current_guess < random_number){ 
            std::cout << "Guess Higher!\n";
        }
    }
}

bool char_valid(char c){
    return c == 'y' || c == 'n';
}

int main(){
    bool play{true};
    while(play){
        hilo();
        char play_again{};
        while (!char_valid(play_again)){
            std::cout << "Play again? (y/n) ";
            std::cin >> play_again;
            if (play_again == 'n'){
                play = false;
            }
        }
    }
    std::cout << "Thanks for playing!\n";
    return 0;
}
