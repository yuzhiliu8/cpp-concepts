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

TEST_CASE("Insert and delete at head", "[deque]") {
    Deque d1;
    
    // Insert at head
    d1.insertHead(10);
    d1.insertHead(20);
    d1.insertHead(30); // Deque should now be: 30, 20, 10

    Deque expected;
    expected.insertHead(10);
    expected.insertHead(20);
    expected.insertHead(30);

    REQUIRE(d1 == expected);

    // Delete head
    int val = d1.popHead();
    REQUIRE(val == 30); // popHead should return the current head
    REQUIRE(d1.size() == 2);

    // Another deletion
    val = d1.popHead();
    REQUIRE(val == 20);
    REQUIRE(d1.size() == 1);

    // Check equality with manually created deque
    Deque remaining;
    remaining.insertHead(10);
    REQUIRE(d1 == remaining);

    // Delete last element
    val = d1.popHead();
    REQUIRE(val == 10);
    REQUIRE(d1.empty());
}

TEST_CASE("Peek head and tail", "[deque]") {
    Deque d;
    
    // Insert elements
    d.insertHead(5);   // Deque: 5
    d.insertTail(10);  // Deque: 5, 10
    d.insertHead(3);   // Deque: 3, 5, 10
    d.insertTail(15);  // Deque: 3, 5, 10, 15

    REQUIRE(d.peekHead() == 3);  // Head should be 3
    REQUIRE(d.peekTail() == 15); // Tail should be 15

    // Pop head and tail to check peeks update
    d.popHead(); // removes 3, Deque: 5, 10, 15
    d.popTail(); // removes 15, Deque: 5, 10

    REQUIRE(d.peekHead() == 5);
    REQUIRE(d.peekTail() == 10);
}

TEST_CASE("InsertHead, InsertTail and equality", "[deque]") {
    Deque d1;
    Deque d2;

    // Fill d1 using insertHead
    d1.insertHead(3);
    d1.insertHead(2);
    d1.insertHead(1); // Deque: 1, 2, 3

    // Fill d2 using insertTail
    d2.insertTail(1);
    d2.insertTail(2);
    d2.insertTail(3); // Deque: 1, 2, 3

    REQUIRE(d1 == d2);       // They should be equal
    REQUIRE(d1.peekHead() == 1);
    REQUIRE(d1.peekTail() == 3);
}


TEST_CASE("TEST EQUALS", "[deque]"){
    Deque d1(std::vector<int>{1, 2, 3, 4, 5});
    Deque d2;
    d2.insertHead(5);
    d2.insertHead(4);
    d2.insertHead(3);
    d2.insertHead(2);
    d2.insertHead(1);

    Deque empty;

    REQUIRE(d1 == d2);
    REQUIRE(d1 != empty);
    REQUIRE(d2 != empty);

    Deque d3;
    d3.insertTail(5);
    d3.insertTail(5);
    d3.insertTail(5);
    d3.insertTail(5);
    d3.insertTail(5);

    REQUIRE(d3 != d1);

    Deque d4;
    d4.insertTail(1);
    d4.insertTail(2);
    d4.insertTail(3);
    d4.insertTail(4);
    d4.insertTail(5);

    REQUIRE(d4 == d1);
}

TEST_CASE("Remove first occurrence - basic functionality", "[deque]") {
    Deque d;
    d.insertTail(1);
    d.insertTail(2);
    d.insertTail(3);
    d.insertTail(2); // duplicate to check only first is removed

    d.remove(2); // remove first 2
    REQUIRE(d.size() == 3);
    REQUIRE(d.toString() == "1 -> 3 -> 2"); // first 2 removed

    d.remove(1); // remove head
    REQUIRE(d.size() == 2);
    REQUIRE(d.toString() == "3 -> 2");

    d.remove(2); // remove tail
    REQUIRE(d.size() == 1);
    REQUIRE(d.toString() == "3");

    d.remove(3); // remove last element
    REQUIRE(d.empty());
    REQUIRE(d.size() == 0);
    REQUIRE(d.toString() == "");
}

TEST_CASE("Remove from empty deque", "[deque]") {
    Deque d;
    REQUIRE_NOTHROW(d.remove(10)); // should do nothing
    REQUIRE(d.empty());
}

TEST_CASE("Remove element not in deque", "[deque]") {
    Deque d;
    d.insertTail(1);
    d.insertTail(2);
    d.insertTail(3);

    d.remove(10); // element not present
    REQUIRE(d.size() == 3);
    REQUIRE(d.toString() == "1 -> 2 -> 3"); // no change
}

TEST_CASE("Remove head in single-element deque", "[deque]") {
    Deque d;
    d.insertHead(42);

    d.remove(42);
    REQUIRE(d.empty());
    REQUIRE(d.size() == 0);
    REQUIRE(d.toString() == "");
}

TEST_CASE("Remove tail in two-element deque", "[deque]") {
    Deque d;
    d.insertTail(1);
    d.insertTail(2);

    d.remove(2); // remove tail
    REQUIRE(d.size() == 1);
    REQUIRE(d.toString() == "1");

    d.remove(1); // remove head (also last element now)
    REQUIRE(d.empty());
}

TEST_CASE("Remove middle element in three-element deque", "[deque]") {
    Deque d;
    d.insertTail(1);
    d.insertTail(2);
    d.insertTail(3);

    d.remove(2); // middle
    REQUIRE(d.size() == 2);
    REQUIRE(d.toString() == "1 -> 3");
}

TEST_CASE("Remove duplicate values - only first occurrence", "[deque]") {
    Deque d;
    d.insertTail(1);
    d.insertTail(2);
    d.insertTail(2);
    d.insertTail(2);
    d.insertTail(3);

    d.remove(2);
    REQUIRE(d.toString() == "1 -> 2 -> 2 -> 3");
    REQUIRE(d.size() == 4);
}

TEST_CASE("Remove multiple elements sequentially", "[deque]") {
    Deque d;
    d.insertTail(1);
    d.insertTail(2);
    d.insertTail(3);

    d.remove(1); // head
    d.remove(3); // tail
    d.remove(2); // last remaining
    REQUIRE(d.empty());
    REQUIRE(d.size() == 0);
}
