#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  this->clear();
  delete head;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  size = x.getLength();
  for(int i = 0; i < x.getLength(); i++) {
    this->insert(i, x.getEntry(i));
  }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  this->clear();
  size = x.getLength();
  for(int i = 0; i < x.getLength(); i++) {
    this->insert(i, x.getEntry(i));
  }
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return (size == 0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return size;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if(position > 1 && position <= (size + 1)) {
    size++;
    Node<T> *node = new Node<T>(item, node);
    Node<T> *temp = head;
    for(int i = 1; i < (position - 1); i++) {
      temp = temp->getNext();
    }
    if(temp != temp->getNext()) {node->setNext(temp->getNext());}
    node->setItem(item);
    temp->setNext(node);
    return true;
  } else if (position == 1) {
    size++;
    head = new Node<T>(item, head);
    return true;
  }
  return false;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  if(position > 1 && position < size) {
    size--;
    Node<T> *node = head;
    Node<T> *temp;
    for(int i = 1; i < (position); i++) {
      node = node->getNext();
    }
    temp = node->getNext();
    node->setNext(node->getNext()->getNext());
    delete temp;
    temp = nullptr;
    return true;
  } else if (position == 1) {
    size--;
    Node<T> *temp = head;    
    head = head->getNext();
    delete temp;
    temp = nullptr;
    return true;
  } 
  return false;
}

template <typename T>
void LinkedList<T>::clear()
{
  Node<T> *node = head;
  Node<T> *temp = head;
  for(int i = 0; i < size; i++) {
    temp = node->getNext();
    node->setNext(nullptr);
    delete node;
    node = temp;
  }
  size = 0;
  head = nullptr;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if(position > 0 && position <= size) {
    Node<T> *node = head;
    for(int i = 1; i < position; i++) {
      node = node->getNext();
    }
    return node->getItem();
  }
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position > 0 && position <= size) {
    Node<T> *node = head;
    for(int i = 1; i < position; i++) {
      node = node->getNext();
    }
    node->setItem(newValue);
  }
}
