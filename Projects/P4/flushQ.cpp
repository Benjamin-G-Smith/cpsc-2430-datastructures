// Ben Smith
// flushQ.cpp
// 11/2/2017
// Version 1.0

// PURPOSE: Class implementation for the flushQ.h. Allows the user to create
//  a flushQ object with the ability to enqueue, dequeue, and flush.
// ASSUMPTIONS: Assumes that input is positive and valid. Assumes that the
//  multiple in flush is positive and a decent value.
#include "flushQ.h"

flushQ::flushQ(){
  capacity = 20;
  size = 0;
  heapArray = new int[capacity];
}
flushQ::flushQ(const flushQ& rhs)
{
  size = rhs.size;
  heapArray = new int[size];
  for(int i = 1; i <= size; i++){
    heapArray[i] = rhs.heapArray[i];
  }
}
flushQ& flushQ::operator=(const flushQ& rhs)
{
  if(this != &rhs){
    delete [] heapArray;
    heapArray = new int[rhs.size];
    for(int i = 1; i <= size; i++){
      heapArray[i] = rhs.heapArray[i];
    }
  }
  return *this;
}
flushQ::~flushQ()
{
  delete [] heapArray;
}
void flushQ::flush(int multiple)
{
  for(int i = 1; i <= size; i++){
    if(heapArray[i] != 0 && heapArray[i] % multiple == 0){
      deleteItem(i);
      i = 1;
    }
  }
  if(heapArray[1] % multiple == 0 && heapArray[1] != 0){
    deleteItem(1);
  }

}
bool flushQ::isEmpty()
{
  return size == 0;
}
int flushQ::dequeue()
{
  int value = heapArray[1];
  heapArray[1] = 0;
  swap(heapArray[1],heapArray[size]);
  size--;
  heapifyDown();
  return value;
}
void flushQ::deleteItem(int index)
{
  heapArray[index] = 0;
  swap(heapArray[index],heapArray[size]);
  size--;
  heapifyDown();
}
void flushQ::enqueue(int data)
{
  if(size+1 == capacity){
    resize();
  }
  else{
  insert(data, heapArray);
  }

}
void flushQ::insert(int data, int heapArray[])
{
  int current = ++size;
  heapArray[current] = data;
  while(current > 1 && heapArray[current] > heapArray[current/2]){
    swap(heapArray[current], heapArray[current/2]);
    current = current/2;
  }
}
void flushQ::heapifyDown()
{
  int index = 1;
  bool done = false;
  while(2*index <= size && !done){
    int lrg = index;
    if(heapArray[2*index] > heapArray[index]){
      lrg = 2*index;
    }
    if((2*index)+1 <= size && heapArray[(2*index)+1] > heapArray[lrg]){
      lrg = 2*index + 1;
    }
    if(lrg != index){
      swap(heapArray[index],heapArray[lrg]);
      index = lrg;
    }
    else
      done = true;
    }
}
void flushQ::swap(int& val1, int& val2)
{
  int temp = val1;
  val1 = val2;
  val2 = temp;
}
void flushQ::resize()
{
  int tsize = 2 * capacity;
  int* temp = new int[tsize];
  for(int i = 1; i <= capacity; i++){
    temp[i] = heapArray[i];
  }
  delete [] heapArray;
  heapArray = temp;
  capacity = tsize;
}
