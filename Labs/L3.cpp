// Ben Smith
// L3.cpp
// 10-6-2017

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
 
struct Node
{
  int data;
  Node* next;
};

int findMeanValue(Node* list);
Node* findSpecificValue(int value, Node* head);

int main()
{
  Node* head = new Node;
  srand(time(0));
  int firstValue = 1;//rand() % 10 + 1;
  int count = 9;
  int meanValue = 0;
  
  head->data = firstValue;
  head->next = nullptr;  

  Node* tempPtr = head;
  Node* walker = head;
  int data = 0;

  while(count){
    tempPtr->next = new Node;
    tempPtr = tempPtr->next;
    tempPtr->data = firstValue += 2;
    count--;
  }
  tempPtr->next = nullptr;
  meanValue = findMeanValue(head);

  while(walker){
    data = walker->data;
    cout << data << endl;
    walker = walker->next;
  }
  if(deleteValue(findSpecificValue(13,head))){
    cout << 13 << "was deleted" << endl;
  }
    return 0;
}
bool insertValue(Node* found){
  if(found){
    Node* insertPtr = found->next;
    insertPtr->next = found->next;
    found->next = new Node;
    
  }
  return false;
}
bool deleteValue(Node* found){
  if(found){
    Node* delPtr = found->next;
    found->next = delPtr->next;
    delete delPtr;
    return true;
  }
  return false;
    
}
int findMeanValue(Node* head)
{
  Node* tempPtr = head;
  double total = 0;
  double count = 0;
  double meanValue = 0;

  while(tempPtr){
    total += tempPtr->data;
    tempPtr = tempPtr->next;
    count++;
  }
  meanValue = (total / count);
  
  return static_cast<int>(meanValue);
}
Node* findSpecificValue(int value, Node* head){
  Node* tempPtr = head;

  while(tempPtr && tempPtr->data != value){
    if(tempPtr->next->data == value){
      return tempPtr;
    }
    tempPtr = tempPtr->next;
  }
  return nullptr;
}
