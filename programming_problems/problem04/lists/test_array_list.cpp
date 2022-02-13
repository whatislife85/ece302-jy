#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.getEntry(0) == 0);
  REQUIRE(list.getEntry(1) == 0);
  REQUIRE(list.isEmpty());
  REQUIRE(list.insert(1, 1));
  REQUIRE(list.getEntry(1) == 1);
  REQUIRE(list.getLength() == 1);
  REQUIRE(list.insert(2, 2));
  REQUIRE(list.getEntry(2) == 2);
  REQUIRE(list.getLength() == 2);
  REQUIRE(!list.isEmpty());
  list.setEntry(1, 3);
  REQUIRE(list.getLength() == 2);
  REQUIRE(list.getEntry(1) == 3);
  REQUIRE(list.getEntry(2) == 2);
  REQUIRE(list.remove(1));
  REQUIRE(list.getLength() == 1);
  REQUIRE(!list.isEmpty());
  REQUIRE(list.getEntry(1) == 2);
  REQUIRE(list.getEntry(2) == 0);
  list.clear();
  REQUIRE(list.isEmpty());
  REQUIRE(!list.getLength());
  REQUIRE(list.getEntry(1) == 0);
  REQUIRE(list.getEntry(2) == 0);
}
