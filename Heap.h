#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "uniquePointer.h"

//map string shared_ptr

template <typename T>
class Heap {
private:
    std::vector<UniquePtr<T>> data;
    bool isMinHeap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallestOrLargest = i;

        if (left < data.size() && compare(*data[left], *data[smallestOrLargest])) {
            smallestOrLargest = left;
        }
        if (right < data.size() && compare(*data[right], *data[smallestOrLargest])) {
            smallestOrLargest = right;
        }
        if (smallestOrLargest != i) {
            std::swap(data[i], data[smallestOrLargest]);
            heapifyDown(smallestOrLargest);
        }
    }

    void heapifyUp(int i) {
        while (i != 0 && compare(*data[i], *data[parent(i)])) {
            std::swap(data[i], data[parent(i)]);
            i = parent(i);
        }
    }

    bool compare(const T& a, const T& b) const {
        return isMinHeap ? a < b : a > b;
    }

public:
    explicit Heap(bool minHeap = true) : isMinHeap(minHeap) {}

    void insert(T value) {
        data.push_back(UniquePtr<T>(new T(value)));
        heapifyUp(data.size() - 1);
    }

    T extractRoot() {
        if (data.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        T rootValue = *data[0];
        data[0] = std::move(data.back());
        data.pop_back();
        if (!data.empty()) {
            heapifyDown(0);
        }
        return rootValue;
    }

    const T& peekRoot() const {
        if (data.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        return *data[0];
    }

    int size() const {
        return data.size();
    }

    bool isEmpty() const {
        return data.empty();
    }
};
