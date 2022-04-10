#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"
#include "linked_list.hpp"

TEST_CASE( "Tests", "[deque]" ) {
  Deque<int> deque;
  REQUIRE(deque.isEmpty());
  deque.pushBack(1);
  REQUIRE(!deque.isEmpty());
  deque.pushFront(2);
  REQUIRE(!deque.isEmpty());
  REQUIRE(deque.front() == 2);
  REQUIRE(deque.back() == 1);
  deque.popFront();
  REQUIRE(!deque.isEmpty());
  REQUIRE(deque.front() == 1);
  REQUIRE(deque.back() == 1);
  deque.popBack();
  REQUIRE(deque.isEmpty());
}
