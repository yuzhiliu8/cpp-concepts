#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "deque.hpp"

TEST_CASE("Deque is initially empty", "[deque]") {
    Deque d;
    REQUIRE(d.toString() == "");
    REQUIRE(d.empty() == true);
    REQUIRE(d.size() == 0);
}

TEST_CASE("Insert head and check contains", "[deque]") {
    Deque d;
    d.insertHead(10);
    REQUIRE(d.contains(10) == true);
    REQUIRE(d.toString() == "10");

    d.insertHead(20);
    REQUIRE(d.contains(20) == true);
    REQUIRE(d.toString() == "20 -> 10");
}

TEST_CASE("Insert tail and check order", "[deque]") {
    Deque d;
    d.insertTail(30);
    REQUIRE(d.contains(30) == true);
    REQUIRE(d.toString() == "30");

    d.insertTail(40);
    REQUIRE(d.contains(40) == true);
    REQUIRE(d.toString() == "30 -> 40");
}

TEST_CASE("Mix head and tail insertions", "[deque]") {
    Deque d;
    d.insertHead(50);
    d.insertTail(60);
    d.insertHead(40);
    REQUIRE(d.toString() == "40 -> 50 -> 60");
}

TEST_CASE("Check empty and size methods", "[deque]") {
    Deque d;
    REQUIRE(d.empty() == true);
    REQUIRE(d.size() == 0);

    d.insertHead(70);
    REQUIRE(d.empty() == false);
    REQUIRE(d.size() == 1);

    d.insertTail(80);
    REQUIRE(d.size() == 2);
}

TEST_CASE("delete head and tail", "[deque]"){

}