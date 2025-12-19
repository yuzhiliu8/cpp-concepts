#ifndef RESIZEABLE_ARRAY_HPP
#define RESIZEABLE_ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template<typename T>
class ResizeableArray{
    public:
        ResizeableArray(){
            this->size_ = 0;
            this->capacity_ = 0;
            this->arr_ = new T[capacity_];
        }

        ResizeableArray(std::initializer_list<T> a){
            size_ = a.size();
            capacity_ = a.size();
            arr_ = new T[capacity_];
            std::size_t i = 0;
            for (auto it = a.begin(); it != a.end(); ++it){
                arr_[i++] = *it;
            }
        }

        std::size_t size() const {
            return size_;
        }

        std::size_t capacity() const {
            return capacity_;
        }

        void push_back(T element){
            expand();
            size_++;
            arr_[size_-1] = element;
        }

        T pop_back(){
            if (size_ == 0){
                throw std::out_of_range("Array is empty");
            }
            size_--;
            T element = arr_[size_];
            return element;
        }

        void insert(int i, T element){

        }

        T get(int i) const {
            if (i < 0 || i >= size_){
                throw std::out_of_range("Index out of bounds");
            }
            return arr_[i];
        }

        void set(int i, T o){}
        void remove(T o){}

        bool empty(){
            return size_ == 0;
        }

    private:
        T* arr_;
        std::size_t size_;
        std::size_t capacity_;

        void expand(){
            if (size_ < capacity_){
                return;
            } 
            // size and capacity are equal
            if (size_ == 0)
                capacity_ = 1;
            else {
                capacity_ *= 2;
            }

            T* new_arr = new T[capacity_];
            for (int i = 0; i < size_; i++){
                new_arr[i] = arr_[i];
            }
            delete[] arr_;
            arr_ = new_arr;
        }
};

#endif