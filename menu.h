#pragma once
#include <iostream>
#include "UniqueLinkedList.h"

void testUniqueLinkedList() {
    UniqueLinkedList<int> uniqueList;
    int choice, value;

    do {
        std::cout << "\n--- UniqueLinkedList Menu ---\n";
        std::cout << "1. Push front\n";
        std::cout << "2. Push back\n";
        std::cout << "3. Pop front\n";
        std::cout << "4. Pop back\n";
        std::cout << "5. Front element\n";
        std::cout << "6. Back element\n";
        std::cout << "7. Check if list is empty\n";
        std::cout << "0. Exit to main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push front: ";
                std::cin >> value;
                uniqueList.pushFront(value);
                break;
            case 2:
                std::cout << "Enter value to push back: ";
                std::cin >> value;
                uniqueList.pushBack(value);
                break;
            case 3:
                uniqueList.popFront();
                std::cout << "Front element removed.\n";
                break;
            case 4:
                uniqueList.popBack();
                std::cout << "Back element removed.\n";
                break;
            case 5:
                if (!uniqueList.isEmpty()) {
                    std::cout << "Front element: " << uniqueList.front() << "\n";
                } else {
                    std::cout << "List is empty.\n";
                }
                break;
            case 6:
                if (!uniqueList.isEmpty()) {
                    std::cout << "Back element: " << uniqueList.back() << "\n";
                } else {
                    std::cout << "List is empty.\n";
                }
                break;
            case 7:
                std::cout << (uniqueList.isEmpty() ? "List is empty.\n" : "List is not empty.\n");
                break;
            case 0:
                std::cout << "Exiting to main menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

