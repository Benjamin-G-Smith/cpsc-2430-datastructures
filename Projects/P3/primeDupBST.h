// Ben Smith
// 10/25/2017
// primeDupBST.h
// version 1.0

// Purpose: The header file for the primeDupBST class

#include <cstdlib>
#include <ctime>
#include <stack>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef PRIMEDUPBST_H
#define PRIMEDUPBST_H

class primeDupBST
{
  public:
    primeDupBST();
    ~primeDupBST();
    bool search(int data);
    // searches for a given vale. Returns if it is in the tree or not
    bool insert(int data);
    // inserts a given value
    bool removeElements();
    // removes multiple random elements
    void printToFile(string file);
    // prints the contents to a file

  private:
    struct TNode{
      int data;
      TNode* left;
      TNode* right;
      TNode(int x = 0){
        data = x;
        left = nullptr;
        right = nullptr;
      }
    };

    int size;
    int* numberOfPrimes;

    TNode* root;
    TNode* privateDeleteSearch(int data);
    // Returns the TNode to the data given
    TNode* findMaxLeft(TNode* delPtr);
    // finds the largest value in the rhs of a tree section

    void deleteTree(TNode* root);
    // deletes all nodes in a BST
    void operator=(const primeDupBST& rhs);
    // defined but not implemented
    void printToFile(TNode* root, ofstream& outPutFile);
    // prints the contents of a BST to a file
    void privateRemoveElement(int data);
    // delets a given element

    bool checkPrime(int data);
    // returns if the data is prime or not
    bool checkCount(int numberOfPrimes[], int prime);
    // determines if there are any duplicats with a given prime
    bool checkCountDelete(int numberOfPrimes[], int prime);
    // determines if there is a value to delete for a given prime
    bool filterNumber(int data);
    // filters the data to be inserted
    bool insert(TNode*& root,int data);
    // inserts a new node into the tree returns false if it cannot
    bool search(TNode*& root, int data);
    // finds the TNode associated with a given data value

    primeDupBST(const primeDupBST& rhs);
    // defined but not implemented
};
#endif
