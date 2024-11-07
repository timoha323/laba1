#pragma once
#include <memory>
#include <vector>
#include "../sharedPointer.h"
#include "stdexcept"
template<typename T>
class DynamicArray {
private:
    size_t size_;
    SharedPointer<T[]> val;
public:
    DynamicArray() : size_(0), val(new T[size_]) {}

    DynamicArray(size_t count, T* items) : size_(count), val(items) {}

    DynamicArray(size_t count) : size_(count), val(new T[count]) {}

    DynamicArray(const DynamicArray &array) : size_(array.size_), val(new T[size_]) {}

    ~DynamicArray() = default;

    size_t Size() const {
        return size_;
    }
    DynamicArray<T>& operator=(const DynamicArray<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] val;
        size_ = other.size_;
        val = SharedPointer<T>(new T[size_]);
        for (size_t i = 0; i < size_; ++i) {
            val[i] = other.val[i];
        }

        return *this;
    }
    DynamicArray<T> operator+(const DynamicArray<T>& other) const {
        DynamicArray<T> result;
        result.Resize(this->size_ + other.size_);
        for (size_t i = 0; i < this->size_; ++i) {
            result[i] = this->val[i];
        }
        for (size_t i = 0; i < other.size_; ++i) {
            result[this->size_ + i] = other.val[i];
        }
        return result;
    }

    DynamicArray<T>& operator +=(const DynamicArray<T>& other) const {
        return (*this) + other;
    }

    void Resize(size_t newSize) {
        if (newSize == size_) return;
        size_ = newSize;
        T *tmp = new T[newSize];
        for(size_t i = 0; i != size_; ++i){
            tmp[i] = val[i];
        }
        val = SharedPointer<T[]>(tmp);
    }

    void Append(T new_el){
        this->Resize(size_ + 1);
        val[size_ - 1] = new_el;
    }

    void Prepend(T new_el){
        DynamicArray<T> a1;
        a1.Append(1);
        (*this) = a1 + (*this);
    }

    const T &operator[](const size_t i) const {
        if(size_ <= i){
            throw std::out_of_range("Index out of range or array is empty");
        }
        return val[i];
    }

    T &operator[](const size_t i) {
        if(size_ <= i){
            throw std::out_of_range("Index out of range or array is empty");
        }
        return val[i];
    }
};