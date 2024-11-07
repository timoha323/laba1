#include "functionalTests.h"
#include "Tests.h"
#include "menu.h"
#include "ui.h"
#include <iostream>
#include <thread>

int main() {
    std::cout << runUnqPtrTests() << std::endl << runShrdPtrTests() << std::endl; ;
    Tests tests;
    std::thread testThread([&tests]() { tests.RunAllTests(); });
    testThread.detach();
    testLinkedList();
    UIMenu();
    return 0;
}
