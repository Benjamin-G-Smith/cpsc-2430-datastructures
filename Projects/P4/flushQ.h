// Ben Smith
// flushQ.h
// 11/2/2017
// Version 1.0

// PURPOSE: Class definition for the flushQ type
// ASSUMPTIONS: Asumes that all numbers are positive

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#ifndef FLUSHQ_H
#define FLUSHQ_H

class flushQ {
  public:
    flushQ();
    flushQ(const flushQ& rhs);
    flushQ& operator=(const flushQ& rhs);
    ~flushQ();

    void enqueue(int data);
    // PRE: There must be an initalized heap array
    // POST: Modifies the heap array to include the data
    // PURPOSE: Allows the user to add a number to the heap array
    int dequeue();
    // PRE: The heap array must have had an element to remove
    // POST: Removes an element from the heap array
    // PURPOSE: Allows the user to dequeue an element from the heap array
    bool isEmpty();
    // Checks to see if the heap array is empty
    void flush(int multiple);
    // PRE: There must be elements in the heap array
    // POST: All elements that are multiples of a given value are removed
    // PURPOSE: Removes all elements that are multiples of a given value
  private:
    int size;
    int capacity;
    int* heapArray;

    void deleteItem(int index);
    // PRE: Given a valid index and a heap array with elements
    // POST: Removes a given element from the heap array.
    //   Also calling heapifyDown
    // PURPOSE: Deletes a given value with a valid index
    void resize();
    // Resizes the heapArray to twice as big
    void insert(int data, int heapArray[]);
    // PRE: Given a valid heap array and a valid piece of data
    // POST: Adds a given value to the heap array.
    // PURPOSE: Allows a value to be inserted into the heap array
    void swap(int& val1, int& val2);
    // Swaps two given values
    void heapifyDown();
    // Structures the heap array into a proper tree
};

#endif
