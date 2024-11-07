#pragma once

class TestHeap {
public:
    void testMinHeapInsertion();
    void testMinHeapExtraction();
    void testMinHeapPeek();
    void testMinHeapEmptyCheck();
    void testMinHeapSize();
    void testMinHeapDuplicateInsertion();
    void testMinHeapExtractFromEmpty();
    void testMinHeapMultipleInsertionsAndExtractions();

    void testMaxHeapInsertion();
    void testMaxHeapExtraction();
    void testMaxHeapPeek();
    void testMaxHeapEmptyCheck();
    void testMaxHeapSize();
    void testMaxHeapDuplicateInsertion();
    void testMaxHeapExtractFromEmpty();
    void testMaxHeapMultipleInsertionsAndExtractions();

    void runAllTests();
};
