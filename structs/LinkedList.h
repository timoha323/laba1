#pragma once
#include "../uniquePointer.h"

template<typename T>
struct Node {
    T data;
    UniquePtr<Node<T>> next;

    explicit Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    UniquePtr<Node<T>> head;
    size_t length;

public:
    LinkedList() : head(nullptr), length(0) {}

    void push_front(const T& value) {
        UniquePtr<Node<T>> newNode = UniquePtr<Node<T>>(new Node<T>(value));
        newNode->next = std::move(head);
        head = std::move(newNode);
        ++length;
    }

    bool isNull(){
        return head.isNull();
    }

    void pop_front() {
        if (!head.isNull()) {
            UniquePtr<Node<T>> oldHead = std::move(head);
            head = std::move(oldHead->next);
            --length;
        }
    }

    size_t size() const {
        return length;
    }

    void clear() {
        while (!head.isNull()) {
            pop_front();
        }
    }

    ~LinkedList(){
        clear();
    }

    T& get_front() const {
        if (!head.isNull()) {
            return head->data;
        } else {
            throw std::runtime_error("List is empty. Cannot get front element.");
        }
    }

};