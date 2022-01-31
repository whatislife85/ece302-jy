#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());

    Bitset b1(-1);
    Bitset b2(0);
    Bitset b3(1);
    Bitset b4("1010");
    Bitset b5("100a");

    REQUIRE(!b1.good());
    REQUIRE(!b2.good());
    REQUIRE(b3.good());
    REQUIRE(b3.size() == 1);
    REQUIRE(!b3.test(0));
    REQUIRE(b4.size() == 4);
    REQUIRE(b4.good());
    REQUIRE(b4.test(0));
    REQUIRE(!b4.test(1));
    REQUIRE(b4.test(2));
    REQUIRE(!b4.test(3));
    REQUIRE(!b4.test(4));
    REQUIRE(!b4.test(-1));
    REQUIRE(!b5.good());
}

TEST_CASE( "Test bitset setting", "[bitset]" ) {
    Bitset b6;
    b6.set(0);
    b6.toggle(1);
    b6.set(2);
    b6.toggle(3);
    b6.reset(4);
    b6.reset(5);
    b6.toggle(6);
    b6.toggle(6);
    b6.reset(7);
    b6.toggle(7);
    b6.toggle(7);

    REQUIRE(b6.test(0));
    REQUIRE(b6.test(1));
    REQUIRE(b6.test(2));
    REQUIRE(b6.test(3));
    REQUIRE(!b6.test(4));
    REQUIRE(!b6.test(5));
    REQUIRE(!b6.test(6));
    REQUIRE(!b6.test(7));
}

TEST_CASE( "TEST bitset string output", "[bitset]" ) {
    Bitset b7;
    b7.toggle(1);
    b7.toggle(3);
    b7.toggle(5);
    b7.toggle(7);
    REQUIRE(b7.asString() == "01010101");
}
