#include "uniquePointer.h"
#include "sharedPointer.h"
#include "ui.h"
#include <iostream>
#include <vector>

void printTools() {
    std::cout << "(1) Create Unique Pointer" << std::endl;
    std::cout << "(2) Create Shared Pointer" << std::endl;
    std::cout << "(3) Create Shared Pointer from existing" << std::endl;
    std::cout << "(4) Delete Shared Pointer" << std::endl;
    std::cout << "(5) Delete Unique Pointer" << std::endl;
    std::cout << "(6) Ref counters in shared vector" << std::endl;
    std::cout << "(7) Exit" << std::endl;
}

void UIMenu() {
    std::cout << "WELCOME TO INTERACTIVE UI MENU\n";
    std::vector<SharedPointer<int>> sharedPointers;
    std::vector<UniquePtr<int>> uniquePointers;

    while (true) {
        std::cout << "Choose one of the following options:\n";
        printTools();
        int option;
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cout << "Enter value:\n";
                int value;
                std::cin >> value;
                uniquePointers.emplace_back(UniquePtr<int>(new int(value)));
                std::cout << "Unique Pointer created with value: " << value << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter value:\n";
                int value;
                std::cin >> value;
                sharedPointers.emplace_back(SharedPointer<int>(new int(value)));
                std::cout << "Shared Pointer created with value: " << value << std::endl;
                break;
            }
            case 3: {
                if (sharedPointers.empty()) {
                    std::cout << "No existing Shared Pointer to duplicate.\n";
                    break;
                }
                sharedPointers.push_back(sharedPointers.back()); // Copy last SharedPointer
                std::cout << "New Shared Pointer created from existing. Ref count: "
                          << sharedPointers.back().use_count() << std::endl;
                break;
            }
            case 4: {
                if (!sharedPointers.empty()) {
                    sharedPointers.pop_back();
                    std::cout << "Last Shared Pointer deleted." << std::endl;
                } else {
                    std::cout << "No Shared Pointer to delete.\n";
                }
                break;
            }
            case 5: {
                if (!uniquePointers.empty()) {
                    uniquePointers.pop_back();
                    std::cout << "Last Unique Pointer deleted." << std::endl;
                } else {
                    std::cout << "No Unique Pointer to delete.\n";
                }
                break;
            }
            case 6: {
                if (!sharedPointers.empty()) {
                    for(const auto& pointer : sharedPointers) {
                        std::cout << pointer.getRefCount() << std::endl;
                    }
                } else {
                    std::cout << "No shared Pointer in vector.\n";
                }
            }
            case 7: {
                std::cout << "Exiting menu." << std::endl;
                return;
            }
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}
