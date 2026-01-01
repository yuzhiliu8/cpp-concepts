#include "io.hpp"

int main(){
    int x{read_number()};
    int y{read_number()};
    write_answer(x + y);
    return 0;
}