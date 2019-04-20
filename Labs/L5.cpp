// Ben Smith
// L5.cpp
// 10/27/2017

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insert(int data, int array[],int& numItems);
void heapifyDown(int numItems, int heapArray[]);
void swap(int& val1, int& val2);
void print(int cap, int heapArray[]);
void deleteElement(int heapArray[], int& numItems);

int main(){
  int numItems = 0;
  const  int cap = 20;
  int* heapArray = new int[cap];
  srand(time(0));

  for(int i = 0; i < 10; i++){
    int randNum = rand() % 10 + 1;
    insert(randNum, heapArray, numItems);
  }
  print(cap,heapArray);
  cout << "num items " << numItems << endl;
  deleteElement(heapArray,numItems);
  heapifyDown(numItems, heapArray);
  cout << "heap down" << endl;
  cout << "num items " << numItems << endl;
  print(cap,heapArray);

  delete [] heapArray;
  return 0;
}
void deleteElement(int heapArray[],int& numItems)
{
  cout << "deleted " << heapArray[1] << endl;
  heapArray[1] = 0;
  swap(heapArray[1],heapArray[numItems]);
  numItems--;

}
void print(int cap, int heapArray[])
{
  for(int i = 0; i < cap; i++){
    cout << heapArray[i] << " ";
  }
  cout << endl;
}
void heapifyDown(int numItems, int heapArray[])
{
  int index = 1;
  bool done = false;
  while(2*index <= numItems && !done){
    int lrg = index;
    if(heapArray[2*index] > heapArray[index]){
      lrg = 2*index;
      cout << "child greater than index" << endl;
    }
    if((2*index)+1 <= numItems && heapArray[(2*index)+1] > heapArray[lrg]){
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
void insert(int data, int array[], int& numItems)
{
  numItems++;
  array[numItems] = data;
  int current = numItems;
  while(current > 1 && array[current] > array[current/2]){
    swap(array[current], array[current/2]);
    current = current/2;
  }
  cout << array[current] << endl;
}
void swap(int& val1, int& val2)
{
  int temp = val1;
  val1 = val2;
  val2 = temp;
}
