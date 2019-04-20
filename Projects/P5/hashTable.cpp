// Ben Smith
// Version 1.0
// hashTable.cpp
// 11/15/2017

// PURPOSE: Implementation of the header hashTable.h

#include "hashTable.h"

hashTable::hashTable(){
  dataSize = 300000;
  table = new HNode[dataSize];
  occurencs = new int[dataSize];
}
hashTable::~hashTable(){
  deleteTable(table);
  delete [] occurencs;
}
void hashTable::deleteTable(HNode table[]){
  delete [] table;
}
void hashTable::insert(string input){
  string word = removeSpaces(input);
  word = removeSpaces(input);

  if(word.length() < 5){
    return;
  }
  int index = hash(word);
  // Check for collisions
  table[index].word = word;
  table[index].key = index;
  table[index].occurencs += 1;
  occurencs[index]++;
}

int hashTable::find(string value){
  return table[hash(value)].occurencs;
}

void hashTable::dump(ofstream& d){
  d << "Top 25 words in file: " << endl;
  int* temp;
  temp = occurencs;
  int top[25];
  int max = 0;

  for(int c = 0; c < 25; c++){
  for(int i = 0; i < dataSize; i++){
    if(max < temp[i]){
      max = temp[i];
      top[c] = i;
      temp[i] = 0;
    }
  }
  max = 0;
}
  d << "Position " << "Occurencs " << "word" << endl;
  for(int i = 0; i < 25; i++){
    int key = top[i];
    if(key > 0){
      int oc = table[key].occurencs;
      string word = table[key].word;
    d << i <<" "<< oc <<" "<< word << endl;
    }
  }
  d << endl;
}
int hashTable::hash(string word){
  int stringValue = 0;
  int wordSize = word.length();
  for(int i = 0; i < wordSize; i++){
    stringValue += (static_cast<int>(word[i]) * i);
  }
  return stringValue % dataSize;
}
string hashTable::removeSpaces(string input)
{
  int l = input.length();
  for(int i=0; i<l; i++){
    if(input[i] == ' ') input.erase(i,1);
   }
  return input;
}
