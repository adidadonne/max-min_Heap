
#include <set>
#ifndef MAMAN3_HEAP_H
#define MAMAN3_HEAP_H
#include "ArrayNode.h"

class Heap {
private:
    ArrayNode* max_heap_arr;
    ArrayNode* min_heap_arr;
    int heap_size;
    int array_size;

    void swap_max(int i, int j);
    void swap_min(int i, int j);
    void copyArray(int* array);
    void Heapify_max(int i);
    void Heapify_min(int i);
    void printHeap(bool max);
    int parent(int i);

public:
    void BuildHeap(int* array, int n);
    void Heapify(int i);
    int HeapExtractMax();
    int HeapExtractMin();
    void HeapInsert( int key);
    void HeapDelete(int i);

    bool keyExist(int key);
    void print();
    void sort();

   void testArrayPrint();

    ~Heap();
    Heap():max_heap_arr(nullptr),min_heap_arr(nullptr),heap_size(0), array_size(0){}
    class HeapUnderflow: public std::exception {
    public :
        const char* what() const noexcept override { return "heap underflow"; }
    };
};


#endif //MAMAN3_HEAP_H
