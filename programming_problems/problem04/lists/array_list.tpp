#include "abstract_list.hpp"
#include <string>
#include <stdio.h>
#include <stdlib.h>

// default constructor
template<typename T> ArrayList<T>::ArrayList() {
  data = new T[101];
  size = 0;
}

// destructor
template<typename T> ArrayList<T>::~ArrayList() {
  delete [] data;
}

// copy constructor
template<typename T> ArrayList<T>::ArrayList(const ArrayList & rhs) {
  data = new T[101];
  for(int i = 1; i <= rhs.getLength(); i++) {
    data[i] = rhs.data[i];
  }
  size = rhs.size;
}

// copy assignment
template<typename T> ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs) {
  if(data) {delete [] data;}
  data = new T[101];
  for(int i = 1; i <= rhs.getLength(); i++) {
    data[i] = rhs.data[i];
  }
  size = rhs.size;
  return *this;
}
  
// determine if a list is empty
template<typename T> bool ArrayList<T>::isEmpty() const noexcept {
  return (size == 0);
}

// return current length of the list
template<typename T> std::size_t ArrayList<T>::getLength() const noexcept {
  return size;
}
  
// insert item at position in the list using 1-based indexing
template<typename T> bool ArrayList<T>::insert(std::size_t position, const T& item) {
  if(position > 100 || position < 1) {return false;}
  for(int i = 100; i >= position; i--) {
    data[i] = data[i-1];
  }
  data[position] = item;
  size++;
  return true;
}

// remove item at position in the list using 1-based indexing
template<typename T> bool ArrayList<T>::remove(std::size_t position) {
 if(position > 100 || position < 1) {return false;}
  for(int i = position; i < 100; i++) {
    data[i] = data[i+1];
  }
  data[100] = 0;
  size--;
  return true;
}

// remove all items from the list
template<typename T> void ArrayList<T>::clear() {
  for(int i = 0; i <= 100; i++) {
    data[i] = 0;
  }
  size = 0;
}

// get a copy of the item at position using 1-based indexing
template<typename T> T ArrayList<T>::getEntry(std::size_t position) const {
  return data[position];
}

// set the value of the item at position using 1-based indexing
template<typename T> void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  if(position <= 100 && position >= 1) {
    data[position] = newValue;
  }
}
