#include <thread>
#include "Tests.h"
#include "menu.h"

int main() {
    Tests tests;
    std::thread testThread([&tests]() { tests.RunAllTests(); });;
    testUniqueLinkedList();
    testThread.join();
    return 0;
}
