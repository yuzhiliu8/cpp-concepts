#include "deque.hpp"

// SLLNode
DNode::DNode(int value, DNode *next, DNode *prev){
    this->value = value;
    this->next = next;
    this->prev = prev;
}

DNode::DNode(int value){
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

Deque::Deque(){
    this->head_ = nullptr;
    this->tail_ = nullptr;
}

Deque::Deque(std::vector<int>& v){
    this->head_ = nullptr;
    this->tail_ = nullptr;

    for (int i = 0; i < v.size(); i++){
        this->insertTail(v[i]);
    }
}

void Deque::insertHead(int x){
    DNode* node = new DNode(x);
    if (head_ == nullptr)
    {
        head_ = node;
        tail_ = node;
        return;
    }

    node->next = head_;
    head_->prev = node;
    head_ = node;
    return;
}

void Deque::deleteHead(){
    if (head_ == nullptr){
        return;
    } else if (this->size() == 1){
        head_ = nullptr;
        tail_ = nullptr;
        return;
    }

    head_ = head_->next;
    head_->prev = nullptr;
}

void Deque::insertTail(int x){
    DNode* node = new DNode(x);

    if (head_ == nullptr)
    {
        head_ = node;
        tail_ = node;
        return;
    }

    node->prev = tail_;
    tail_->next = node;
    tail_ = node;
}

bool Deque::contains(int x){
    if (head_ == nullptr)
    {
        return false;
    }

    DNode* temp = head_;
    while (temp != nullptr)
    {
        if (temp->value == x){
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void Deque::remove(int x){

}

int Deque::size(){
    int count = 0;
    DNode* temp = head_;

    while(temp != nullptr){
        temp = temp->next;
        count++;
    }

    return count;
}

bool Deque::empty(){
    return this->size() == 0;
}

std::string Deque::toString(){
    DNode* temp = head_;
    std::string res = "";

    while (temp != nullptr)
    {
        res += std::to_string(temp->value);
        if (temp->next != nullptr)
        {
            res += " -> ";
        }
        temp = temp->next;
    }
    return res;
}
