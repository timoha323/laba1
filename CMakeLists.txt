cmake_minimum_required(VERSION 3.29)
project(smart_pointer)

set(CMAKE_CXX_STANDARD 26)

add_executable(smart_pointer main.cpp
        uniquePointer.h
        Tests.h
        sharedPointer.h
        menu.h
        Tests.cpp
        menu.cpp
        structs/DynamicArray.h
        structs/ArraySequence.h
        functionalTests.h
        FunctionalTests.cpp
        ui.cpp
        ui.h
)
