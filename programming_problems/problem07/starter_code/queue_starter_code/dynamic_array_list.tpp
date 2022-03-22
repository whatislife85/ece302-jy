#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  capacity = 10;
  size = 0;
  data = new T[capacity];
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  data = new T[x.capacity];
  capacity = x.capacity;
  size = x.size;

  for(int i = 0; i < size; i++) {
    data[i] = x.data[i];
  } 
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  delete [] data;
  size = 0;
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  capacity = x.capacity;
  size = x.size;

  for(int i = 0; i < size; i++) {
    data[i] = x.data[i];
  }
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  DynamicArrayList<T> tempList = y;
  y = this;
  this = tempList;
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  return (size == 0);
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  for(int j = capacity-1; j > position; j--) {
    data[j] = data[j-1];
  }
  data[position] = item;
  size++;
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  for(int j = position; j < capacity; j++) {
    data[j] = data[j+1];
  }
  size--;
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  size = 0;
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  data[position] = newValue;
}
