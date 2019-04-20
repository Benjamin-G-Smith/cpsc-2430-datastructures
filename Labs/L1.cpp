// Ben Smith
// L1.cpp
// 9-22-2017

#include <iostream>

using namespace std;

void evenInput (int size);
int findMax (int evenArray[], int size);

const int MAX = 99;
const int MIN = 11;

int main()
{
  int userIn;
  cout << "Welcome" << endl;
  cout << "How many even numbers do you want jeo?: ";

  cin >> userIn;

  evenInput(userIn);

  cout << "Goodbye" << endl;
  return 0;
}
void  evenInput (int size){
  int* evenNumbers;
  evenNumbers = new int [size];
  int numbersEntered = 0;
  int userNum = 0;
  int maxEven = 0;

  while(numbersEntered < size){
    cout << size - numbersEntered << " remaining entries" << endl;
    cout << "Enter a number between 11-99: ";
    cin >> userNum;

    while(userNum < MIN || userNum > MAX){
      cout << "Number is invalid [11-99]" << endl;
      cin >> userNum;
    }
    if(userNum % 2 == 0){
      evenNumbers[numbersEntered] = userNum;
      numbersEntered++;
    }
  }
  maxEven = findMax(evenNumbers,size);

  for(int i = 0; i < numbersEntered; i++){
    cout << "Value: " << evenNumbers[i]
         << " Address: "<< &evenNumbers[i] << endl;
  }
  cout << endl;
  cout << "Max Even : " << maxEven << endl;

  delete evenNumbers;
}
int findMax ( int evenArray[], int size){
  int max = evenArray[0];

  for(int i = 0; i < size; i++){
    if(max < evenArray[i]){
      max = evenArray[i];
    }
  }
  return max;
}
