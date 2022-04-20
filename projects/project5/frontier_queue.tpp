#include "frontier_queue.hpp"
#include <algorithm>

template <typename T>
State<T> frontier_queue<T>::pop() {
  int position = queue.size() - 1;
  State<T> state = queue[0];
  queue[0] = queue[position];
  queue.erase(queue.begin()+position);
  int testPosition = 0;
  int lowerPosition = (testPosition*2)+1;  
  while(true) {
    lowerPosition = (testPosition*2)+1;
    if( (testPosition*2)+1 >= queue.size() ) {break;}
    else if( (testPosition*2)+2 < queue.size() ) {
      if(queue[ (testPosition*2)+2 ].getFCost() < queue[ (testPosition*2)+1 ].getFCost()) {lowerPosition++;}
    }
    if( queue[testPosition].getFCost() > queue[lowerPosition].getFCost()) {
      State<T> temp = queue[testPosition]; 
      queue[testPosition] = queue[lowerPosition]; 
      queue[lowerPosition] = temp;
      //testPosition = lowerPosition;
    } else {break;}
  }
  return state;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {
  int position = queue.size() - 1;
  State<T> state(p, cost, heur);
  queue.push_back(state);
  while(true) {
    if(position < 1) {break;}
    else if(queue[ (position-1)/2 ].getFCost() <= queue[position].getFCost()) {break;}
    else {queue[position] = queue[ (position-1)/2 ]; position = (position-1)/2; queue[position]=state;}
  }
}

template <typename T>
bool frontier_queue<T>::empty() {
  return queue.empty();
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {
  for(State<T> i : queue) {if (i.getValue() == p) {return true;}}
  return false;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {
  for(State<T>& i : queue) {if(cost < i.getFCost()) {i.updatePathCost(cost);}}
}
