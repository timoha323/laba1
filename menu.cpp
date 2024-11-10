#include <iostream>
#include "menu.h"
#include "structs/LinkedList.h"

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