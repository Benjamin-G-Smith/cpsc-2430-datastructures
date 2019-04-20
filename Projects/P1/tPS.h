// Ben Smith
// tPS.h
// 10/2/2017

// Class file for the tPS.h. Allows the user to create and use stack
//  functions.

#include <cassert>

using namespace std;

#ifndef STACK_H
#define STACK_H

class Stack
{
  public:
  Stack(int s = DEFAULT);
  Stack(const Stack &rhs);
  Stack& operator=(const Stack &rhs);
  ~Stack();
  bool push(int v);
  // Pre: There must be an avalible space to push onto the stack
  // Post: The value v is pushed onto the stack and the top is moved
  bool pop(int &v);
  // Pre: There must be a value on the stack in order to pop
  // Post: The value from the top of the stack is popped off
  const bool isEmpty();

 private:
  const bool isFull();
  static const int DEFAULT = 50;
  int size;
  int top;
  int* arr;
  bool resize();

};
#endif
