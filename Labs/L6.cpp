// Ben Smith
// L6.cpp

#include<iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

struct CNode{
  int population;
  string county;
  string state;
};
void quickSort(CNode table[], int count);
void swap(int& value1, int& value2);
int partition(CNode table[], int low, int high);

int main()
{
  const string fileName = "countyPop.dat";
  ifstream input;
  int pop;
  string location,line;
  const int size = 3141;
  CNode table[size];

  input.open(fileName);
  if(input.fail()){
    cout << "could not open file " << endl;
    return 0;
  }
  int i = 0;
  while(getline(input,line) &&  i < size){// looking through each line of the file
    string lineString = line;
    istringstream lineStream(lineString);
    while(lineStream >> pop){ //looking at every word in each line
      table[i].population = pop;
      lineStream >> location;
      table[i].county = location;
      lineStream >> location;
      lineStream >> location;
      table[i].state = location;
    }
    i++;
  }

  quickSort(table,size);
  for(int i  = 0; i < size; i++){
    int x  = table[i].population;
    string search = "Grand";

    if(table[i].county == search && table[i].state == "Colorado"){
    string state = table[i].state;
    string county = table[i].county;
    cout << x << " "<< state << " " << county << endl;
    cin.get();
    }
  }
  return 0;
}
int partition(CNode data[], int low, int high){
  int x = data[high].population;
  int i = low-1;

  for(int j = low; j <= high - 1; ++j){
    if(data[j].population <= x){
      ++i;
      swap(data[i], data[j]);
    }
  }
  swap(data[i + 1], data[high]);
  return (i +1);
}
void quickSort(CNode table[], int count){
  int startIndex = 0;
  int endIndex = count - 1;
  int top = -1;
  int* stack = new int[count];

  stack[++top] = startIndex;
  stack[++top] = endIndex;

  while (top >= 0)
  {
    endIndex = stack[top--];
    startIndex = stack[top--];

    int p = partition(table, startIndex, endIndex);

    if (p - 1 > startIndex)
    {
      stack[++top] = startIndex;
      stack[++top] = p - 1;
    }

    if (p + 1 < endIndex)
    {
      stack[++top] = p + 1;
      stack[++top] = endIndex;
    }
  }

  delete stack;
}
void swap(int& value1, int& value2){
  int temp = value1;
  value1 = value2;
  value2 = temp;
}
