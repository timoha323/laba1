#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
#include "stdexcept"
template<typename T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> array_;
    size_t capacity_;
    size_t size_;
public:
    ArraySequence() : array_(), capacity_(0), size_(0) {}

    ArraySequence(T* items, size_t count) : array_(count, items), capacity_(count), size_(count) {}

    ArraySequence(const ArraySequence<T>& other) : array_(other.array_), capacity_(other.capacity_), size_(other.size_) {}

    void Resize(size_t new_size){
        if(new_size > capacity_){
            size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
            if(new_capacity < new_size){
                new_capacity = new_size;
            }
            array_.Resize(new_capacity);
            capacity_ = new_capacity;
        }
    }

    T GetFirst() override {
        return array_[0];
    }

    T GetLast() override {
        return array_[size_ - 1];
    }

    T Get(int index) override {
        return array_[index];
    }

    void pop(){
        if(size_ > 0) {
            Resize(size_ - 1);
            size_--;
        }
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || endIndex < 0 || startIndex >= size_ || endIndex >= size_ || startIndex > endIndex) {
            return new ArraySequence<T>();
        }
        T* items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; ++i) {
            items[i - startIndex] = array_[i];
        }
        return new ArraySequence<T>(items, size_t(endIndex - startIndex + 1));
    }

    int GetLength() override {
        return size_;
    }

    Sequence<T>* Append(T item) override {
        Resize(size_ + 1);
        size_++;
        array_[size_ - 1] = item;
        return this;
    }

    Sequence<T>* Prepend(T item) override {
        Resize(size_ + 1);
        size_++;
        for (int i = size_ - 1; i > 0; --i) {
            array_[i] = array_[i - 1];
        }
        array_[0] = item;
        return this;
    }

    Sequence<T>* InsertAt(T item, int index) override {
        if (index < 0 || index > size_) {
            throw std::out_of_range("Index out of range or array is empty");
        }
        Resize(size_ + 1);
        ++size_;
        for (int i = size_ - 1; i > index; --i) {
            array_[i] = array_[i - 1];
        }
        array_[index] = item;
        return this;
    }

    Sequence<T>* Concat(Sequence<T>* other) override {
        ArraySequence<T>* concatenatedList = new ArraySequence<T>();
        for (int i = 0; i < size_; ++i) {
            concatenatedList->Append(array_[i]);
        }
        for (int i = 0; i < other->GetLength(); ++i) {
            concatenatedList->Append(other->Get(i));
        }
        return concatenatedList;
    }
    void Clear(){
        array_.Resize(0);
        capacity_ = 0;
        size_ = 0;
    }
    T& operator[](const size_t i){
        return array_[i];
    }
    const T& operator[](const size_t i) const{
        return array_[i];
    }
};