// Ben Smith
// 10/20/2017
// L4.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>


using namespace std;

struct TNode {
  int data;
  TNode* left;
  TNode* right;
  TNode(int x = 0){
    data = x;
    left = nullptr;
    right = nullptr;
  }
};

//void constructTree(TNode*& root);
void insert(TNode*& auxPtr, int data);
void preOrder(TNode* root);
void postOrder(TNode* root);
void inOrder(TNode* root);
void checkCount(int numberOfPrimes[], int prime);
bool checkPrime(int data);
bool search(TNode* root, int data);
TNode* findMaxLeft(TNode* delPtr);
void privateRemoveElement(int data, TNode* root);
TNode* findMaxLeft(TNode* delPtr);


int main(){
  srand(time(0));
  int* numberOfPrimes = new int[541];
  int prime = 0;
  int count = 100;

  while(count){
    prime = rand() % 541 + 1;
    if(checkPrime(prime)){
        checkCount(numberOfPrimes,prime);
        cout << count << "prime is " << prime << endl;
        count--;
      }
    }
  for(int i = 0; i < 541; i++){
    if(numberOfPrimes[i] > 0){
      cout << i << " [ " << numberOfPrimes[i] << " ]" << endl;
      }
    }

  TNode* root = nullptr;
  for(int i = 0; i < 10; i++){
    int data = rand() % 50 + 1;
    insert(root, data);
  }
  int number = 3;
  while(number){
    int data = rand() % 50 + 1;
    if(numberOfPrimes[data] > 0){
      privateRemoveElement(data, root);
      number--;
    }

  }


  inOrder(root);

  delete [] numberOfPrimes;

  return 0;
}
void privateRemoveElement(int data, TNode* root)
{
  TNode* delPtr = root;
  TNode* parent = nullptr;

  while(delPtr && delPtr->data != data){
    parent = delPtr;
    if(data < delPtr->data){
      delPtr = delPtr->left;
    }
    else{
      delPtr = delPtr->right;
    }
  }
  bool left = (delPtr == parent->left);
  if(delPtr->left == nullptr && delPtr->right == nullptr){
    cin.get();
    cout << "no children" << endl;
    if(delPtr == root){
      root = nullptr;
      return;
    }
    else if(left){
      parent->left = nullptr;
    }
    else{
      parent->right = nullptr;
    }
    return;
  }
  else if(!delPtr->left || !delPtr->right){
    cin.get();
    cout << "one child" << endl;
    TNode* child = (delPtr->left)?delPtr->left:delPtr->right;
    if(delPtr == root){
      root = child;
      return;
    }
    else if(left){
      parent->left = child;
    }
    else{
      parent->right = child;
    }
    return;
  }
  else{
    cin.get();
    cout << "two children" << endl;
    TNode* swap = findMaxLeft(delPtr);
    int temp = delPtr->data;
    delPtr->data = swap->data;
    swap->data = temp;
    if(swap != delPtr){
      swap->left = nullptr;
    }
    else{
      swap->right = nullptr;
    }
    //delete delPtr;
    return;
  }

  //root

    // calls the search
    // Checks to see if the element data is zero in the count array
    // removes the node if the count in the array for that prime is zero

}
TNode* findMaxLeft(TNode* delPtr)
{
  TNode* min = delPtr->right;

  while(min->left != nullptr){
    min = min->left;
  }
  return min;
}
bool search(TNode* root, int data)
{
  TNode* current = root;
  std::stack<TNode*> s;
  bool done = false;
    while(!done){
      if(current){
        s.push(current);
        if(current->data == data){
          return true;
        }
        current = current->left;
      }
      else{
        if(!s.empty()){
          current = s.top();
          s.pop();
          if(current->data == data){
            return true;
          }
          current = current->right;
        }
        else{
          done = true;
        }
      }
    }
    return false;
  // root
    // calls the search
    // Checks to see if the element data is zero in the count array
    // removes the node if the count in the array for that prime is zero
}
bool checkPrime(int data)
{
  if(data > 3 && data % 2 != 0){
    for(int i = 3; i < data; i++){
        if(data % i == 0){
            return false;
        }
      }
      return true;
  }
  return false;
}
void checkCount(int numberOfPrimes[], int prime)
{
  numberOfPrimes[prime]++;
}
void preOrder(TNode* root){
  if(root){
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
  }

}
/*TNode* findMaxLeft(TNode* delPtr)
{
  TNode* current = delPtr;
  if(current == nullptr){
  while(current->right != nullptr){
    current = current->right;
  }
  return current;
}
return nullptr;
}*/
void inOrder(TNode* root)
{
  if(root){
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
  }
}
void insert(TNode*& root, int data){
  if(root == nullptr){
    // create node, put in data
    root = new TNode(data);
    //root->data = data;
    //root->data = data;
    return;
  }
  else if(root->data > data){
    return insert(root->left, data);
  }
  else if(root->data < data){
    return insert(root->right, data);
  }
  else{
    return;
  }
}
