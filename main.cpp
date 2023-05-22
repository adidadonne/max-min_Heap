#include <iostream>
#include "Heap.h"
#include "stdio.h"

using namespace std;

int main(int argc, const char** argv) {


    int choice=0;
    while(true)
    {
        cout<<"please press 1 if you wish to BuildHeap or press 2 if you wish to Exit "<<endl;
        cin >> choice;

        if (choice == 1)
        {
            int *array;
            int size;
            /// if command line arguments are provided
            if (argc > 1) {
                // Calculate the size of the array
                size = argc - 1;

                // Create an array to store the command-line arguments
                array = new int[size];
                // Convert and store the command-line arguments in the array
                for (int i = 0; i < size; i++) {
                    array[i] = atoi(argv[i]);
                }
            } else
                /// if we receive the array from the user
            {
                cout << "please enter the size of your heap" << endl;
                cin >> size;
                array = new int[size];
                cout << "please enter your heap elements" << endl;
                for (int i = 0; i < size; i++) {
                    cin >> array[i]; //read input from the user and store in the array
                }
            }
            Heap heap;
            heap.BuildHeap(array,size);
            while(true)
            {
                cout<<"please choose a command:"<<endl;
                cout<<"1. Heapify"<<endl;
                cout<<"2.HeapExtractMax"<<endl;
                cout<<"3.HeapExtractMin"<<endl;
                cout<<"4.HeapInsert"<<endl;
                cout<<"5.HeapDelete"<<endl;
                cout<<"6.print heap"<<endl;
                cout<<"7.sort heap"<<endl;
                cout<<"8. Exit"<<endl;

                cin >> choice;
                switch (choice) {
                    case 1:
                    {
                        int i = 0;
                        while (true)
                        {
                            cout << "please enter index: "<<endl;
                            cin >> i;
                            if (i <= 0 || i > size)
                            {
                                cout << "Invalid choice. Index entered is not within the heap size boundaries" << endl;
                            }
                            else break;
                        }
                                heap.Heapify(i);
                                break;
                    }
                    case 2: {
                        cout << " the max number is " << heap.HeapExtractMax() << endl;
                        break;
                    }
                    case 3: {
                        cout << "the min number is " << heap.HeapExtractMin() << endl;
                        break;
                    }
                    case 4: {
                        int key = 0;
                        while (true) {
                            cout << "please enter a new key" << endl;
                            cin >> key;
                            if (heap.keyExist(key)) { cout << "key already exists" << endl; }
                            else break;
                        }
                        heap.HeapInsert(key);
                        break;
                    }
                    case 5:
                    {
                        int i = 0;
                        while (true)
                        {
                            cout << "please enter index: "<<endl;
                            cin >> i;
                            if (i <= 0 || i > size)
                            {
                                cout << "Invalid choice. Index entered is not within the heap size boundaries" << endl;
                            }
                            else break;
                        }
                        heap.HeapDelete(i-1);
                        break;
                    }
                    case 6:
                    {
                        heap.print();
                        heap.testArrayPrint();
                        break;
                    }
                    case 7:
                    {
                        heap.sort();
                        break;
                    }
                    case 8:
                        cout << "Exiting the program" << endl;
                        return 0;
                    default:
                        cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
                        break;
                }
            }
        }
        if (choice == 2) ///if user choose to exit
        {
            return 0;
        } else
        {
            cout << "Invalid choice"<< endl;
        }
    }
    return 0;
}

