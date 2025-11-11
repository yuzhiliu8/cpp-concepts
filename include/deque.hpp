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
        Deque(std::vector<int>& v);
        void insertHead(int x);
        void deleteHead();

        void insertTail(int x);
        void deleteTail(int x);
        bool contains(int x);

        int popHead();
        int peekHead();
        int popTail();
        int peekTail();

        void remove(int x);
        int size();
        bool empty();

        std::string toString();

        bool operator==(Deque& other);
    
    private:
        DNode* head_;
        DNode* tail_;
};

#endif