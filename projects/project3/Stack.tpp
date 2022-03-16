//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() 
{
  currentSize = 0;
  headPtr = nullptr;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
  clear();
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
  return !currentSize;
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
  return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
  if(headPtr) {
    headPtr = new Node<ItemType>(newItem, headPtr);
  } else {
    headPtr = new Node<ItemType>(newItem);
  }
  currentSize++;
  return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
  if(!isEmpty()) {
    return headPtr->getItem();
  }
  throw("peeking empty stack");
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
  if(isEmpty()) {return false;}
  
  Node<ItemType> *node = headPtr;
  headPtr = headPtr->getNext();
  node->setNext(nullptr);
  delete node;
  node = nullptr;

  currentSize--;
  return true;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
  while(!isEmpty()) {
    pop();
  }
  currentSize = 0;
  headPtr = nullptr;
}  // end clear

