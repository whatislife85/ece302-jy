#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());
  pq.add(2);
  REQUIRE(!pq.isEmpty());
  REQUIRE(pq.peek() == 2);
  pq.add(1);
  REQUIRE(pq.peek() == 2);
  pq.remove();
  REQUIRE(pq.peek() == 1);
  REQUIRE(!pq.isEmpty());
  pq.remove();
  REQUIRE(pq.isEmpty());
  
}
