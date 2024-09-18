#pragma once
#include <utility>
#include <stdexcept>
#include "uniquePointer.h"

template <typename T>
struct node {
    T data;
    UniquePtr<node<T>> next;
    UniquePtr<node<T>> prev;

    node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class UniqueLinkedList {
private:
    UniquePtr<node<T>> head;
    UniquePtr<node<T>> tail;

public:
    UniqueLinkedList() : head(nullptr), tail(nullptr) {}

    void pushFront(const T& value) {
        UniquePtr<node<T>> newNode(new node<T>(value));
        if (head.isNull()) {
            tail = std::move(newNode);
        } else {
            head->prev = std::move(newNode);
            head->prev->next = std::move(head);
        }
        head = std::move(newNode);
    }

    void pushBack(const T& value) {
        UniquePtr<node<T>> newNode(new node<T>(value));
        if (tail.isNull()) {
            head = std::move(newNode);
            tail = std::move(head);
        } else {
            newNode->prev = std::move(tail);
            tail->next = std::move(newNode);
            tail = std::move(tail->next);
        }
    }

    void popFront() {
        if (!head.isNull()) {
            head = std::move(head->next);
            if (!head.isNull()) {
                head->prev.reset();
            } else {
                tail.reset();
            }
        }
    }

    void popBack() {
        if (!tail.isNull()) {
            tail = std::move(tail->prev);
            if (!tail.isNull()) {
                tail->next.reset();
            } else {
                head.reset();
            }
        }
    }

    T& front() const {
        if (!head.isNull()) {
            return head->data;
        }
        throw std::runtime_error("List is empty");
    }

    T& back() const {
        if (!tail.isNull()) {
            return tail->data;
        }
        throw std::runtime_error("List is empty");
    }

    bool isEmpty() const {
        return head.isNull();
    }
};