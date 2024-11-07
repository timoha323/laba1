#include "HeapTest.h"
#include "Heap.h"
#include <cassert>
#include <iostream>

void TestHeap::testMinHeapInsertion() {
    Heap<int> minHeap(true);
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    assert(minHeap.peekRoot() == 5);
    std::cout << "testMinHeapInsertion passed\n";
}

void TestHeap::testMinHeapExtraction() {
    Heap<int> minHeap(true);
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    assert(minHeap.extractRoot() == 5);
    assert(minHeap.peekRoot() == 10);
    std::cout << "testMinHeapExtraction passed\n";
}

void TestHeap::testMinHeapPeek() {
    Heap<int> minHeap(true);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(10);
    assert(minHeap.peekRoot() == 10);
    std::cout << "testMinHeapPeek passed\n";
}

void TestHeap::testMinHeapEmptyCheck() {
    Heap<int> minHeap(true);
    assert(minHeap.isEmpty() == true);
    minHeap.insert(10);
    assert(minHeap.isEmpty() == false);
    std::cout << "testMinHeapEmptyCheck passed\n";
}

void TestHeap::testMinHeapSize() {
    Heap<int> minHeap(true);
    minHeap.insert(25);
    minHeap.insert(35);
    assert(minHeap.size() == 2);
    minHeap.extractRoot();
    assert(minHeap.size() == 1);
    std::cout << "testMinHeapSize passed\n";
}

void TestHeap::testMinHeapDuplicateInsertion() {
    Heap<int> minHeap(true);
    minHeap.insert(10);
    minHeap.insert(10);
    assert(minHeap.peekRoot() == 10);
    assert(minHeap.size() == 2);
    std::cout << "testMinHeapDuplicateInsertion passed\n";
}

void TestHeap::testMinHeapExtractFromEmpty() {
    Heap<int> minHeap(true);
    assert(minHeap.isEmpty() == true);

    try {
        minHeap.extractRoot();
        assert(false);
    } catch (...) {
        std::cout << "testMinHeapExtractFromEmpty passed\n";
    }
}

void TestHeap::testMinHeapMultipleInsertionsAndExtractions() {
    Heap<int> minHeap(true);
    for (int i = 0; i < 100; i++) {
        minHeap.insert(i);
    }
    assert(minHeap.size() == 100);
    for (int i = 0; i < 100; i++) {
        assert(minHeap.extractRoot() == i);
    }
    assert(minHeap.isEmpty() == true);
    std::cout << "testMinHeapMultipleInsertionsAndExtractions passed\n";
}

void TestHeap::testMaxHeapInsertion() {
    Heap<int> maxHeap(false);
    maxHeap.insert(10);
    maxHeap.insert(50);
    maxHeap.insert(20);
    assert(maxHeap.peekRoot() == 50);
    std::cout << "testMaxHeapInsertion passed\n";
}

void TestHeap::testMaxHeapExtraction() {
    Heap<int> maxHeap(false);
    maxHeap.insert(40);
    maxHeap.insert(60);
    maxHeap.insert(20);
    assert(maxHeap.extractRoot() == 60);
    assert(maxHeap.peekRoot() == 40);
    std::cout << "testMaxHeapExtraction passed\n";
}

void TestHeap::testMaxHeapPeek() {
    Heap<int> maxHeap(false);
    maxHeap.insert(25);
    maxHeap.insert(15);
    maxHeap.insert(50);
    assert(maxHeap.peekRoot() == 50);
    std::cout << "testMaxHeapPeek passed\n";
}

void TestHeap::testMaxHeapEmptyCheck() {
    Heap<int> maxHeap(false);
    assert(maxHeap.isEmpty());
    maxHeap.insert(20);
    assert(!maxHeap.isEmpty());
    std::cout << "testMaxHeapEmptyCheck passed\n";
}

void TestHeap::testMaxHeapSize() {
    Heap<int> maxHeap(false);
    maxHeap.insert(50);
    maxHeap.insert(100);
    assert(maxHeap.size() == 2);
    maxHeap.extractRoot();
    assert(maxHeap.size() == 1);
    std::cout << "testMaxHeapSize passed\n";
}

void TestHeap::testMaxHeapDuplicateInsertion() {
    Heap<int> maxHeap(false);
    maxHeap.insert(10);
    maxHeap.insert(10);
    assert(maxHeap.peekRoot() == 10);
    assert(maxHeap.size() == 2);
    std::cout << "testMaxHeapDuplicateInsertion passed\n";
}

void TestHeap::testMaxHeapExtractFromEmpty() {
    Heap<int> maxHeap(false);
    assert(maxHeap.isEmpty());

    try {
        maxHeap.extractRoot();
        assert(false);
    } catch (...) {
        std::cout << "testMaxHeapExtractFromEmpty passed\n";
    }
}

void TestHeap::testMaxHeapMultipleInsertionsAndExtractions() {
    Heap<int> maxHeap(false);
    for (int i = 0; i < 100; i++) {
        maxHeap.insert(i);
    }
    assert(maxHeap.size() == 100);
    for (int i = 99; i >= 0; i--) {
        assert(maxHeap.extractRoot() == i);
    }
    assert(maxHeap.isEmpty());
    std::cout << "testMaxHeapMultipleInsertionsAndExtractions passed\n";
}

void TestHeap::runAllTests() {

    testMinHeapInsertion();
    testMinHeapExtraction();
    testMinHeapPeek();
    testMinHeapEmptyCheck();
    testMinHeapSize();
    testMinHeapDuplicateInsertion();
    testMinHeapExtractFromEmpty();
    testMinHeapMultipleInsertionsAndExtractions();


    testMaxHeapInsertion();
    testMaxHeapExtraction();
    testMaxHeapPeek();
    testMaxHeapEmptyCheck();
    testMaxHeapSize();
    testMaxHeapDuplicateInsertion();
    testMaxHeapExtractFromEmpty();
    testMaxHeapMultipleInsertionsAndExtractions();
    std::cout<<"ALL TESTS PASSED\n\n\n";
}
