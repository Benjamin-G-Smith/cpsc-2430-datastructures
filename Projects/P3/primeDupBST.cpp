// Ben Smith
// 10/25/2017
// primeDupBST.cpp
// version 1.0

// Purpose: The implementation for the primeDupBST header file

#include "primeDupBST.h"

primeDupBST::primeDupBST()
{
  root = nullptr;
  size = 800;
  numberOfPrimes = new int[size];
}
primeDupBST::~primeDupBST()
{
  deleteTree(root);
  delete [] numberOfPrimes;
  // Delets the binary search tree
  // deallocates the counter array
  // deletes any other nodes
}
void primeDupBST::deleteTree(TNode* root)
{
  if(root){
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
}
bool primeDupBST::search(int data)
{
  return search(root, data);
  //privateSearch(data);
  // return true or false based on the result
}
bool primeDupBST::search(TNode*& root, int data)
{
  TNode* current = root;
  stack<TNode*> s;
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
}
primeDupBST::TNode* primeDupBST::privateDeleteSearch(int data)
{
  TNode* current = root;
  stack<TNode*> s;
  bool done = false;
    while(!done){
      if(current){
        s.push(current);
        if(current->data == data){
          return current;
        }
        current = current->left;
      }
      else{
        if(!s.empty()){
          current = s.top();
          s.pop();
          if(current->data == data){
            return current;
          }
          current = current->right;
        }
        else{
          done = true;
        }
      }
    }
    return nullptr;
    // removes the node if the count in the array for that prime is zero
}

void primeDupBST::printToFile(string file)
{
  ofstream outPutFile;
  outPutFile.open(file);
  printToFile(root, outPutFile);
  outPutFile.close();
}
void primeDupBST::printToFile(TNode* root, ofstream& outPutFile)
{
  if(root){
    printToFile(root->left,outPutFile);
    outPutFile << root->data << endl;
    printToFile(root->right, outPutFile);
  }
}
bool primeDupBST::insert(int data)
{
  return insert(root,data);
}
bool primeDupBST::insert(TNode*& root, int data)
{
  if(filterNumber(data)){
      TNode* current = nullptr;
      TNode* parent = nullptr;
      if(root == nullptr){
        TNode* newNode = new TNode(data);
        root = newNode;
        current = root;
      }
      else{
        current = root;
        while(current != nullptr){
          if(data < current->data){
            parent = current;
            current = current->left;
          }
          else{
            parent = current;
            current = current->right;
          }
        }
        TNode* newNode = new TNode(data);
        if(data < parent->data){
          parent->left = newNode;
        }
        else{
          parent->right = newNode;
        }
      }
      return true;
  }
  else
  return false;

  // Call the filter
  // only adds if filter returns true
  // add to the BST
}
bool primeDupBST::removeElements()
{
  // Deletes a set amount of nodes from the BST
  // Issue with the delete causes segfault not able to figure out why
  // something broken in delete. Works part of the time.
  int count = 20;
  while(count){
    int randNumber = rand() % size + 1;
    if(checkPrime(randNumber)){
      if(checkCountDelete(numberOfPrimes,randNumber)){
        count--;
        privateRemoveElement(randNumber);
      }
    }
  }
  return true;
}
void primeDupBST::privateRemoveElement(int data)
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
  if(!delPtr->left && !delPtr->right){
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
    // Known issue somewhere in the delete no sure what is is causing
    // memory leak
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
    return;
  }
    // calls the search
    // Checks to see if the element data is zero in the count array
    // removes the node if the count in the array for that prime is zero

}
primeDupBST::TNode* primeDupBST::findMaxLeft(TNode* delPtr)
{
  TNode* min = delPtr->right;

  while(min->left != nullptr){
    min = min->left;
  }
  return min;
}
bool primeDupBST::checkPrime(int data)
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
bool primeDupBST::checkCount(int numberOfPrimes[], int prime)
{
  int value = prime;
  if(numberOfPrimes[value] == 0){
    numberOfPrimes[value]++;
    return true;
  }
  else{
    numberOfPrimes[value]++;
    return false;
  }
}
bool primeDupBST::checkCountDelete(int numberOfPrimes[], int prime)
{
  int value = prime;
  if(numberOfPrimes[value] >= 1){
    numberOfPrimes[value]--;
    return true;
  }
  else{
    return false;
  }
}
bool primeDupBST::filterNumber(int data)
{
   if(checkPrime(data)){
     if(numberOfPrimes[data] == 0){
       numberOfPrimes[data] += 1;
       return true;
     }
       numberOfPrimes[data] += 1;
       return false;
   }
   return false;
    // only returns true if the number is prime and not a dupe
    // check against the numberOfPrimes array
    // if the numberOfPrimes is not zero for that prime, iterate the count at that prime
    // return false
    // return true if is prime and the numberOfPrimes for that prime is zero
}
