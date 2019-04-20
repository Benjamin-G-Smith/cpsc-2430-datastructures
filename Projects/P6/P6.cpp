// Ben Smth
// P6.cpp
// 11/24/2017

// PURPOSE: Initalizes a vector container to store 1000 values that get
//  get alterd according to their 'parity'. The program runs until no more
//  alterations are made to the data set.
// ASSUMPTIONS: All values stored are positive. Assumes that 1 is even.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

void initalize(vector<int>& storage, int size);
bool removePrimeParity(vector<int>& storage, int size);
bool removeNonPrimeParity(vector<int>& storage, int size);
bool checkPrime(int value);

int main()
{
  srand(time(0));
  vector<int> storage;
  vector<int>::iterator element;
  const int size = 1000;
  bool done = false;
  int itemsRemoved = 0;

  cout << "Press Enter to begin program:";
  cin.get();

  initalize(storage, size);

  while(!done){
    bool primeClean = removePrimeParity(storage, size);
    bool nonPrimeClean = removeNonPrimeParity(storage, size);
    for(element = storage.begin(); element < storage.end(); element++){
      cout <<setw(3) << *element << " ";
    }
    cout << endl << endl;
    cout <<"Number of items removed "<<itemsRemoved << endl;
    cout << endl;
    // Terminating condition
    if(primeClean && nonPrimeClean){
      done = true;
    }
    itemsRemoved++;
  }
  for(element = storage.begin(); element < storage.end(); element++){
    cout <<setw(3) << *element << " ";
  }
  cout << endl;
  cout <<"Number of items removed "<<itemsRemoved << endl;
  return 0;
}
// Check for prime
bool checkPrime(int data)
{
  if(data == 2){
    return true;
  }
  else if(data > 3 && data % 2 != 0){
      for(int i = 3; i < data; i++){
          if(data % i == 0){
              return false;
          }
        }
        return true;
    }
    return false;
}
// Check for non-prime
bool checkNonPrime(int data){
  if(data == 1){
    return true;
  }
  else if(data > 3 && data % 2 == 0){
        return true;
    }
    return false;
}
// removes all non prime parities
bool removeNonPrimeParity(vector<int>& storage, int size){
  int firstVal = 0;
  int thirdVal = 0;
  int delIndex = 0;
  for(int i = 0; i < (int) storage.size()-1; i += 3){
    firstVal = storage[i];
    thirdVal = storage[i+2];
    if((checkNonPrime(firstVal) && checkNonPrime(thirdVal))){
      delIndex = i+1;
      int mid = storage[delIndex];
      if(checkPrime(mid)){
        storage.erase(storage.begin() + delIndex);
        return false;
      }
    }
  }
  return true;
}
// removes all primes in parity
bool removePrimeParity(vector<int>& storage, int size){
  int firstVal = 0;
  int thirdVal = 0;
  int delIndex = 0;
  for(int i = 0; i < (int) storage.size()-1; i += 3){
    firstVal = storage[i];
    thirdVal = storage[i+2];
    if(checkPrime(firstVal) && checkPrime(thirdVal)){
      delIndex = i+1;
      int mid = storage[delIndex];
      if(checkPrime(mid)){
        storage.erase(storage.begin() + delIndex);
        return false;
      }
    }
  }
  return true;
}
// initalizes the container with values
void initalize(vector<int>& storage, int size)
{
  int randNum = 0;
  for(int i = 0; i < size; i++){
    randNum = rand() % 100 + 1;
    if(randNum % 5 != 0){
      storage.push_back(randNum);
    }
  }
}
