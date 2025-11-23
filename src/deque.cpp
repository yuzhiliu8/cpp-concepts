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

Deque::Deque(const std::vector<int>& v){
    this->head_ = nullptr;
    this->tail_ = nullptr;

    for (int i = 0; i < v.size(); i++){
        this->insertTail(v[i]);
    }
}

Deque::~Deque(){
    while (head_ != nullptr){
        DNode* temp = head_;
        head_ = head_->next;
        delete temp;
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

int Deque::popHead(){
    if (empty()){
        throw std::out_of_range("Cannot pop from empty deque");
    } else if (this->size() == 1){
        int val = head_->value;
        head_ = nullptr;
        tail_ = nullptr;
        return val;
    }

    int val = head_->value;
    head_ = head_->next;
    head_->prev = nullptr;
    return val;
}

int Deque::peekHead(){
    if (empty()){
        throw std::out_of_range("Cannot peek in empty deque!");
    }
    return head_->value; 
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

int Deque::popTail(){
    if (empty()){
        throw std::out_of_range("Cannot pop from empty deque!");
    }
    else if (size() == 1){
        int val = tail_->value;
        head_ = nullptr;
        tail_ = nullptr;
    }

    int val = tail_->value;
    tail_ = tail_->prev;
    tail_->next = nullptr;
    return val;
}

int Deque::peekTail(){
    if (empty()){
        throw std::out_of_range("Cannot peek in empty deque");
    }

    return tail_->value;
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

void Deque::remove(int x){ //removes first occurrence
    if (empty()){ 
        return;
    }
    DNode* curr = head_;

    while (curr != nullptr){
        if (curr->value != x){
            curr = curr->next;
            continue;
        }

        if (curr->prev == nullptr){ // head
            popHead();
        }
        else if (curr->next == nullptr){ //tail
            popTail();
        } else { //middle
            DNode* p = curr->prev;
            DNode* n = curr->next;
            p->next = n;
            n->prev = p;
            delete curr;
        }
        return;
    }
}

int Deque::size() const {
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

bool Deque::operator==(const Deque& deque) const {
    if (this->size() != deque.size()){
        return false;
    }
    DNode* temp1 = head_;
    DNode* temp2 = deque.head_;

    while (temp1 != nullptr){
        if (temp1->value != temp2->value){
            return false;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
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
