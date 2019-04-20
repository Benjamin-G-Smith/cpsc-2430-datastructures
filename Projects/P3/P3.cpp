// Ben Smith
// 10/25/2017
// P3.cpp
// version 1.0

// Purpose: allows the user to create a binary search tree with the
//  provided package. Adds 100 values to the BST then writes those numbers
//  to a file. Deletes 20 random numbers then writes the results to a file.

#include "primeDupBST.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
  srand(time(0));
  // Allocates memory for a new tree
  primeDupBST tree;
  int count = 100;
  cout << "Press Enter to run program";
  cin.get();
  cout << "Adding 100 values to the tree..." << endl;
  // ads to the BST
  while(count){
    int randNumber = rand() % 800 + 1;
    if(tree.insert(randNumber)){
      count--;
    }
  }
  tree.printToFile("P3outl1.txt");
  cout << "100 values added to the binary search tree" << endl;
  cout << "Wrote to file P3outl1.txt" << endl;
  cout << "Press Enter to remove elements:";
  cin.get();
  // removes random elements
  if(tree.removeElements()){
    cout << "done" << endl;
  }
  cout << "Writing to file P3outl2.txt" << endl;
  tree.printToFile("P3outl2.txt");
  return 0;
}
