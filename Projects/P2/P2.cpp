// Ben Smith
// 10/7/2017
// Version 1.0
// P2.cpp

// PURPOSE: Creates a linked list of fifty integers and sorts them in ascending
//  order. The program then deletes the smallest, largest, and a value in the
//  middle.

// INPUTS: The user starts the program.
// PROCESSING: A link list of fifty integers is created and sorted in ascending
//  order

// OUTPUTS: The filenames of the output files. Along with the smallest, largest
//  ,and middle value.
// EXAMPLES:
// Press Enter to begin program:
// Writing to P2OutputA.txt...
// [Smallest value]:  10 was deleted
// [Middle value]:   74 was deleted
// [Largest value]: 106 was deleted
// Writing to P2OutputB.txt...

// ASSUMPTIONS: Assumes that the program will only be run once. Also Assumes
//  functionality, no errors to be thrown.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Node{
  int data;
  Node* next;
};
void createLink(Node*& head, const int linkSize);

bool insertInOrder(Node*& h, int d);
void writeToFile(Node*& head, string file);
bool checkPrime(int fileNumber);
int findNextPrime(int fileNumber);
void deleteSmallestValue(Node*& head);
void deleteLargestValue(Node*& head);
void deleteMiddleValue(Node*& head, const int linkSize);
void deleteList(Node*& head);

int main(){
  const string outPutA = "P2OutputA.txt";
  const string outPutB = "P2OutputB.txt";
  const int linkSize = 50;

  cout << "Press Enter to begin program: ";
  cin.get();

// Creates a sorted linked list with 50 nodes
  Node* head = nullptr;
  createLink(head,linkSize);

  writeToFile(head,outPutA);
  deleteSmallestValue(head);
  deleteMiddleValue(head,linkSize);
  deleteLargestValue(head);
  writeToFile(head,outPutB);
  deleteList(head);
  return 0;
}
void createLink(Node*& head, const int linkSize)
{
  int count = 0;
  int num = 0;
  srand(time(0));
  while(count < linkSize) {
    num = rand() % linkSize + 1;
    if(checkPrime(num)){
      insertInOrder(head, findNextPrime(num));
      count++;
    }
  }
}
void deleteList(Node*& head)
{
  Node* tempPtr = head;
  Node* delPtr;
  while(tempPtr){
    delPtr = tempPtr;
    tempPtr = delPtr->next;
    delete delPtr;
  }
}
void deleteSmallestValue(Node*& head)
{
  Node* delPtr = head;
  head = head->next;
  cout <<"[Smallest value]:  "<< delPtr->data << " was deleted" << endl;
  delete delPtr;
}
void deleteMiddleValue(Node*& head, const int linkSize)
{
  Node* tempPtr = head;
  int count = 0;
  while(count < linkSize/2){
    tempPtr = tempPtr->next;
    count++;
  }
  Node* delPtr = tempPtr->next;
  tempPtr->next = delPtr->next;
  cout <<"[Middle value]:   "<< delPtr->data << " was deleted " << endl;
  delete delPtr;
}
void deleteLargestValue(Node*& head)
{
  Node* tempPtr = head;
  while(tempPtr->next->next != nullptr){
    tempPtr = tempPtr->next;
  }
  Node* delPtr = tempPtr->next;
  tempPtr->next = nullptr;
  cout <<"[Largest value]: "<< tempPtr->data << " was deleted" << endl;
  delete delPtr;
}
void writeToFile(Node*& head,string file)
{
  cout << "Writing to " << file <<"..."<< endl;
  ofstream outPutFile;
  outPutFile.open(file);
  Node* tempPtr = head;
  while(tempPtr){
    int d = tempPtr->data;
    outPutFile << d << endl;
    tempPtr = tempPtr->next;
  }
}
bool insertInOrder(Node*& h, int d)
{
  Node* temp;
  Node* ptr = h;
  temp = new Node;

  if(temp == nullptr){
    return false;
  }

  temp->data = d;
  temp->next = nullptr;

  if(h == nullptr){
  	h = temp;
  }
  else if(h->data > temp->data){
    temp->next = h;
    h = temp;
  }
  else{
  	ptr = h;
    while(ptr->next != nullptr && ptr->next->data < d){
      ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
  }
  return true;
}
int findNextPrime(int prime)
{
  int num = prime;
  bool found = false;
  while(!found){
      num += 2;
      found = checkPrime(num);
    }
  return num * 2;
}
bool checkPrime(int fileNumber)
{
  if(fileNumber % 2 != 0 && fileNumber != 2){
      for(int i = 3; i < fileNumber; i++){
        if(fileNumber % i == 0){
          return false;
        }
      }
    return true;
  }
  return false;
}
