#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>
#include <string>
#include <vector>

//int only
class DNode {
    public:
        DNode(int value, DNode* next, DNode* prev);
        DNode(int value);
        int value;
        DNode* next;
        DNode* prev;
};


class Deque {
    public:
        Deque();
        Deque(const std::vector<int>& v);
        ~Deque();

        void insertHead(int x);
        int popHead();
        int peekHead();

        void insertTail(int x);
        int popTail();
        int peekTail();

        bool contains(int x);
        void remove(int x);
        int size() const;
        bool empty();

        std::string toString();

        bool operator==(const Deque& other) const;
    
    private:
        DNode* head_;
        DNode* tail_;
};

#endif