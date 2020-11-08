#include <iostream>
#include "destination.h"
#include "car.h"
#include "stack.h"

using namespace std;

void InitStack(StackT& s) {
  s.size = 0;
  s.top = 0;
  return;
}


void Push(StackT& s, ItemT item) {
  if (s.size < MAX_STACK)

  {
    s.top++;
    s.spur[s.top] = item;
    s.size++;

  }

  else {
    cout << ITEM_OVERFLOW_ERROR << endl;
  }

  return;
}


ItemT Pop(StackT& s) {
  ItemT value;

  if (s.size == 0) {
    cout << NO_ITEM_ERROR << endl;
    return NO_ITEM;
  } else {
    value = s.spur[s.top];
    s.top--;
    s.size--;
    return value;
  }
}


ItemT Top(const StackT& s)

{
  if (s.size == 0) {
   cout << NO_ITEM_ERROR << endl;
    return NO_ITEM;
  }

  else 

  {return s.spur[s.top];}

}


bool IsEmpty(const StackT& s) {
  bool isEmpty;
  
  isEmpty = false; 

  if (s.size <= 0) {
    isEmpty = true;
  } else if (s.size > 0) {
    isEmpty = false;
  }

  return isEmpty;
}


bool IsFull(const StackT& s) {
  if (s.size == MAX_STACK) {
    return true;
  }

  else

  return false;
}


int Size(const StackT& s)

{
  return s.size;
}