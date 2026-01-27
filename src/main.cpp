#include <iostream>
#include <vector>
#include "deque.hpp"
#include "resizeable_array.hpp"

int* ptr_test(){
    int* value = new int(5);
    std::cout << *value << std::endl;
    return value;
}

class A{
    public:
        A(int x): x(x){}

    private:
        int x;

};

int main(){
    A a = 5;

    ResizeableArray<int> arr;
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n\n";
    arr.push_back(1);
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n\n";
    arr.push_back(2);
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n\n";
    arr.push_back(3);
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n\n";
    arr.push_back(4);
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n\n";

    arr.push_back(5);
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n\n";

    arr.push_back(6);
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n\n";
    arr.push_back(7);
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << "Capacity: " << arr.capacity() << "\n\n";

    arr.pop_back();
    // std::cout << "POP: " << x << "\n";
    // std::cout << "Size: " << arr.size() << "\n";
    // std::cout << "Capacity: " << arr.capacity() << "\n\n";

    return 0;
}
