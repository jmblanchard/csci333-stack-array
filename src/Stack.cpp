#include "Stack.h"
#include <iostream>
#include <assert.h>

Stack::Stack(int initialSize) {
  theStack = new int[initialSize];
  top = 0;
  maxSize = initialSize;
}

Stack::~Stack() {
  delete[] theStack;
}

void Stack::push(int value) {
  //if theStack is full
  // create new stack twice as big
  // copy all elements to new stack
  // delete old stack
  // point old stack pointer to new stack
  if (top == maxSize) {
    maxSize *= 2;
    int *newStack = new int[maxSize];
    for (int i = 0; i < top; ++i) {
      newStack[i] = theStack[i];
    }
    delete[] theStack;
    theStack = newStack;
    newStack = NULL;
  }

  assert(top != maxSize);
  theStack[top] = value;
  top++;
}

int Stack::pop() {
  top--;
  return theStack[top];
}

int Stack::peek() {
  return theStack[top-1];
}

int Stack::size() {
  return top;
}
