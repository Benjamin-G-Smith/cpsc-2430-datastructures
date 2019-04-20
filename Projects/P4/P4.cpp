// Ben Smith
// 11/2/2017
// Version 1.0
// P4.cpp

// Assumes that the numbers being written to the outPutFile are the numbers
//  in the heap array after flush(value) is called. If 1 is provided no
//  numbers will appear in the outPutFile because all numbers are a multiple
//  of 1. Therefore all elements in the heap array are removed.

#include "flushQ.h"

using namespace std;

int main()
{
  srand(time(0));
  ofstream outPutFile;
  flushQ test;

  int count = 35;
  int multiple = 0;

// Adds 35 random numbers to the heap array
  for(int i = 0; i < count; i++){
    int num = rand() % count + 1;
    test.enqueue(num);
  }
  cout << endl;
  cout << "Enter a number to flush: ";
  cin >> multiple;

  cout << "flushing..." << endl;
  test.flush(multiple);
// Flushes the multiples of a given value out of the heap array
  cout << "Writing to file..." << endl;
  outPutFile.open("P4Output.txt");
// Writes the result of the heap array flush to outPutFile
  outPutFile << "Heap after flush called with: " << multiple << endl;
  while(!test.isEmpty()){
     int value = test.dequeue();
     outPutFile << value << endl;
  }
  outPutFile.close();
  return 0;
}
