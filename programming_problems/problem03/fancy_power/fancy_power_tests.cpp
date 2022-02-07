#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancy_power.hpp"
#include <math.h>

// write your test cases here
TEST_CASE("Test case", "fancy power"){
  /*for (int i = 0; i < 6; i++) {
    for(int j = 0; j < 6; j++) {
	REQUIRE(fancy_power(i, j) == pow(i, j));
    }
  }*/
  REQUIRE(fancy_power(2, 10) == pow(2, 10));
  //REQUIRE(true);
  
}
