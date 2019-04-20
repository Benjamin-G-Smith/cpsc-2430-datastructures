// Ben Smith
// Version 1.0
// hashTable.h
// 11-15-2017

// PURPOSE: Header file for the hashTable class

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class hashTable
{
  public:
    hashTable();
    ~hashTable();
    void insert(string word);
    int find(string word);
    void dump(ofstream& d);

  private:
    struct HNode{
      string word;
      int key;
      HNode* next;
      int occurencs;
      HNode(){
        occurencs = 0;
        key = 0;
      }
    };
    int dataSize;
    int* occurencs;
    HNode* table;
    int hash(string word);
    hashTable(const hashTable& rhs);
    hashTable& operator=(const hashTable& rhs);
    void addToBucket(int value);
    void deleteTable(HNode table[]);
    void deleteLinkedList(HNode h);
    string removeSpaces(string word);
};
#endif
