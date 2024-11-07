#include <iostream>
#include "menu.h"
#include "Heap.h"
#include "structs/LinkedList.h"

void testHeap() {
    bool isMinHeap;
    std::cout << "Create min-heap (1) or max-heap (0): ";
    std::cin >> isMinHeap;

    Heap<int> heap(isMinHeap);
    int choice, value;

    do {
        std::cout << "\n--- Heap Menu ---\n";
        std::cout << "1. Insert element\n";
        std::cout << "2. Extract root element\n";
        std::cout << "3. Peek root element\n";
        std::cout << "4. Check if heap is empty\n";
        std::cout << "5. Get heap size\n";
        std::cout << "0. Exit to main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
            std::cin >> value;
            heap.insert(value);
            std::cout << "Inserted value: " << value << "\n";
            break;
            case 2:
                if (!heap.isEmpty()) {
                    std::cout << "Extracted root element: " << heap.extractRoot() << "\n";
                } else {
                    std::cout << "Heap is empty, cannot extract.\n";
                }
            break;
            case 3:
                if (!heap.isEmpty()) {
                    std::cout << "Root element: " << heap.peekRoot() << "\n";
                } else {
                    std::cout << "Heap is empty.\n";
                }
            break;
            case 4:
                std::cout << (heap.isEmpty() ? "Heap is empty.\n" : "Heap is not empty.\n");
            break;
            case 5:
                std::cout << "Heap size: " << heap.size() << "\n";
            break;
            case 0:
                std::cout << "Exiting to main menu...\n";
            break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
void printMenu() {
    std::cout << "\nLinkedList Menu:\n";
    std::cout << "1. Add element\n";
    std::cout << "2. Remove front element\n";
    std::cout << "3. View front element\n";
    std::cout << "4. View size of the list\n";
    std::cout << "0. Exit\n";
}

void testLinkedList() {
    LinkedList<int> list;

    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter element to add: ";
                std::cin >> value;
                list.push_front(value);
                std::cout << value << " added to the list.\n";
                break;
            }
            case 2: {
                if (list.size() == 0) {
                    std::cout << "The list is empty. Cannot remove an element.\n";
                } else {
                    list.pop_front();
                    std::cout << "Removed front element.\n";
                }
                break;
            }
            case 3: {
                if (list.size() == 0) {
                    std::cout << "The list is empty. No front element to view.\n";
                } else {
                    std::cout << "Front element: " << list.get_front() << "\n";
                }
                break;
            }
            case 4: {
                std::cout << "Size of the list: " << list.size() << "\n";
                break;
            }
            case 0: {
                std::cout << "Exiting...\n";
                return;
            }
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
}