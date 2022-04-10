#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "Node.hpp"
#include "abstract_list.hpp"

template <typename T> class LinkedList : public AbstractList<T> {
public:
  // default constructor
  LinkedList();

  // copy constructor
  LinkedList(const LinkedList &x);

  // destructor
  ~LinkedList();

  // copy assignment
  LinkedList &operator=(const LinkedList &x);

  // swap two lists
  void swap(LinkedList &x, LinkedList &y);

  // determine if a list is empty
  bool isEmpty() const;

  // return current length of the list
  std::size_t getLength() const;

  // insert item at position in the list using 1-based indexing
  bool insert(std::size_t position, const T &item);

  // remove item at position in the list using 1-based indexing
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 1-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 1-based indexing
  void setEntry(std::size_t position, const T &newValue);

private:
  // pointer to first node in chain, contains the first item in list
  Node<T> *headPtr;

  // current count of list items
  std::size_t itemCount;

  // Locates a specified node in linked list
  // @pre position is number of desired node, greater than 0 and less than or
  // equal to itemCount
  // @post pointer to specific node is returned
  // @param position -- number of the node to be found
  // @return ponter to node at position
  Node<T> *getNodeAt(int position) const;
};

#include "linked_list.tpp"

#endif
