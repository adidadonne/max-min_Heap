
#include "Heap.h"
#include <cmath>
#include <iostream>


void Heap::BuildHeap(int *array, int n)
{
    heap_size=n;
    array_size=n;
    copyArray(array);
    int startIdx=(n/2)-1;
    for(int i=startIdx; i>=0;i--)
    {
        Heapify(i);
    }
}
void Heap::copyArray(int *array)
{
    max_heap_arr= new ArrayNode[heap_size];
    min_heap_arr= new ArrayNode[heap_size];
    for (int i=0;i<heap_size;i++)
    {
        max_heap_arr[i].key=array[i];
        max_heap_arr[i].index=i;
        min_heap_arr[i].key=array[i];
        min_heap_arr[i].index=i;
    }
}

Heap::~Heap()
{
    delete [] max_heap_arr;
    delete [] min_heap_arr;
}
void Heap::Heapify_max(int i)
{
    int left= 2*i;
    int right= 2*i+1;
    int largest=i;

    if (left < heap_size && max_heap_arr[left].key > max_heap_arr[largest].key) {
        largest = left;
    }
    if (right < heap_size && max_heap_arr[right].key > max_heap_arr[largest].key) {
        largest = right;
    }
    if (largest != i) {
        swap_max(i, largest);
        Heapify_max(largest);
    }
}

void Heap::Heapify_min(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    // Find the smallest among the current node and its children
    if (left < heap_size && min_heap_arr[left].key < min_heap_arr[smallest].key)
        smallest = left;
    if (right < heap_size && min_heap_arr[right].key < min_heap_arr[smallest].key)
        smallest = right;

    // If the smallest value is not the current node, swap and recursively heapify
    if (smallest != i)
    {
        swap_min(i, smallest);
        Heapify_min(smallest);
    }
}

void Heap::Heapify(int i)
{
    Heapify_max(i);
    Heapify_min(i);
}
int Heap::HeapExtractMax()
{
    if(heap_size<1)
    {
        throw HeapUnderflow();
    }
    int max=max_heap_arr[0].key;
    int min_index=max_heap_arr[0].index;

    swap_max(0, heap_size - 1);
    swap_min(min_index, heap_size - 1);

    max_heap_arr[min_heap_arr[min_index].index].index=0;


    heap_size--;

    Heapify(0);
    return max;
}

int Heap::HeapExtractMin()
{
    if(heap_size<1)
    {
        throw HeapUnderflow();
    }
    int min= min_heap_arr[0].key;
    int index_in_max=min_heap_arr[0].index;

    swap_min(0,heap_size-1);
    swap_max(index_in_max,heap_size-1);

    min_heap_arr[max_heap_arr[index_in_max].index].index = 0;

    heap_size--;

    Heapify(0);

    return min;
}

int Heap::parent(int i)
{
    return (i - 1) / 2;
}

void Heap::HeapInsert( int key)
{
    if(heap_size==array_size)
    {
        ArrayNode* new_max_heap_array= new ArrayNode[array_size*2];
        ArrayNode* new_min_heap_array= new ArrayNode[array_size*2];
        for(int i=0;i<heap_size;i++)
        {
            new_max_heap_array[i]=max_heap_arr[i];
            new_min_heap_array[i]=min_heap_arr[i];
        }
        array_size*=2;
        delete[] max_heap_arr;
        delete[] min_heap_arr;
        max_heap_arr=new_max_heap_array;
        min_heap_arr=new_min_heap_array;
    }
    max_heap_arr[heap_size]=ArrayNode(key,heap_size);
    min_heap_arr[heap_size]=ArrayNode(key,heap_size);
    heap_size++;
    int i= heap_size-1;

    /// Heapify the element until it satisfies the heap property
    while (i > 0 && max_heap_arr[parent(i)].key < max_heap_arr[i].key)
    {
        swap_max(i, parent(i));
        i = parent(i);
    }
}

void Heap::HeapDelete(int i)
{
    if(heap_size<1)
    {
        throw HeapUnderflow();
    }

    swap_max(i,heap_size-1);
    swap_min(max_heap_arr[heap_size-1].index,heap_size-1);
   // swap_max(i,heap_size-1);
   heap_size--;

    Heapify(i);
}
void Heap::swap_max(int i, int j)
{
    ArrayNode temp = max_heap_arr[i];

    /// updating index information on the other heap array
    min_heap_arr[max_heap_arr[j].index].index=i;
    min_heap_arr[max_heap_arr[i].index].index=j;

    /// swapping
    max_heap_arr[i]=max_heap_arr[j];
    max_heap_arr[j]=temp;

}

void Heap::swap_min(int i, int j)\
{
    ArrayNode temp = min_heap_arr[i];
    /// updating index information on the other heap array
    max_heap_arr[min_heap_arr[j].index].index=i;
    max_heap_arr[min_heap_arr[i].index].index=j;

    /// swapping
    min_heap_arr[i]=min_heap_arr[j];
    min_heap_arr[j]=temp;
}
//Heap::Heap():heap_arr(nullptr),heap_size(0){}

bool Heap::keyExist(int key)
{
    for( int i=0;i<heap_size;i++)
    {
        if( max_heap_arr[i].key==key)
        {
            return true;
        }
    }
    return false;
}

void Heap::printHeap(bool max)
{
    if (heap_size == 0)
    {
        std::cout << "Heap is empty." << std::endl;
        return;
    }

    // Calculate the height of the heap
    int height = static_cast<int>(std::log2(heap_size)) + 1;

    int level = 0;
    int nodesInLevel = 1;
    int nodesCounted = 0;

    for (int i = 0; i < heap_size; i++)
    {
        // Print the spaces before the first node of the level
        int spaces = static_cast<int>(std::pow(2, height - level) - 1);
        for (int j = 0; j < spaces; j++)
        {
            std::cout << "   ";
        }

        // Print the node value
        if(max) {
            std::cout << max_heap_arr[i].key;
        }
        else
        {
            std::cout<<min_heap_arr[i].key;
        }
        nodesCounted++;

        // Print the spaces between nodes
        int spacesBetween = static_cast<int>(std::pow(2, height - level + 1) - 1);
        for (int j = 0; j < spacesBetween; j++)
        {
            std::cout << "   ";
        }

        // Move to the next level
        if (nodesCounted == nodesInLevel)
        {
            std::cout << std::endl;
            level++;
            nodesInLevel *= 2;
            nodesCounted = 0;
        }
    }
}


void Heap::print()
{
    std::cout<<"max heap is:"<<std::endl;
    printHeap(true);
    std::cout<<std::endl;
    std::cout<<"min heap is:"<<std::endl;
    printHeap(false);
}
/*
void Heap::print() {

    std::cout<<"max heap:"<<std::endl;
    /// Calculate the number of levels in the heap
    int levels = log2(heap_size) + 1;
    /// Index of the first element in the current level
    int levelStart = 0;

    for (int level = 0; level < levels; level++) {
        int levelEnd = min(levelStart + pow(2, level) - 1, heap_size); // Index of the last element in the current level

        for (int i = levelStart; i <= levelEnd; i++)
        {
            if(i<heap_size)
            {
                std::cout << heap_arr[i] << " ";
            }

        }

        std::cout << std::endl;

        levelStart = levelEnd + 1; // Move to the next level

    }
}*/

void Heap::testArrayPrint()
{
    std::cout<<std::endl;
    std::cout<<"min heap array:";
    for(int i=0;i<heap_size;i++)
    {
        std::cout<<min_heap_arr[i].key<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"max heap array:";
    for(int i=0;i<heap_size;i++)
    {
        std::cout<<max_heap_arr[i].key<<" ";
    }
    std::cout<<std::endl;
}

void Heap::sort()
{
    int size=heap_size;
    ArrayNode* sorted_max_heap_array= new ArrayNode[array_size];
    ArrayNode* sorted_min_heap_array= new ArrayNode[array_size];
    for(int i=0, j=size-1;i<size;i++, j--)
    {
        int temp=HeapExtractMax();
        sorted_max_heap_array[i].key=temp;
        sorted_max_heap_array[i].index=j;
        sorted_min_heap_array[j].key=temp;
        sorted_min_heap_array[j].index=i;
    }

    delete[] max_heap_arr;
    delete [] min_heap_arr;
    heap_size=size;
    min_heap_arr=sorted_min_heap_array;
    max_heap_arr=sorted_max_heap_array;
}