#include "catch2/catch.hpp"
#include "resizeable_array.hpp"

TEST_CASE("ResizeableArray default constructor", "[resize]") {
    ResizeableArray<int> arr;
    REQUIRE(arr.size() == 0);
    REQUIRE(arr.capacity() == 0);
    REQUIRE(arr.empty());
}

TEST_CASE("ResizeableArray array constructor", "[resize]") {
    int nums[5] = {1, 2, 3, 4, 5};
    ResizeableArray<int> arr = {1, 2, 3, 4, 5};
    // Assumes constructor works correctly
    REQUIRE(arr.size() == 5);
    for (int i = 0; i < 5; ++i) {
        REQUIRE(arr.get(i) == nums[i]);
    }
}

TEST_CASE("push_back and expand", "[resize]") {
    ResizeableArray<int> arr;

    SECTION("single push_back") {
        arr.push_back(10);
        REQUIRE(arr.size() == 1);
        REQUIRE(arr.get(0) == 10);
    }

    SECTION("multiple push_back and automatic expand") {
        for (int i = 0; i < 20; ++i) {
            arr.push_back(i);
        }
        REQUIRE(arr.size() == 20);
        for (int i = 0; i < 20; ++i) {
            REQUIRE(arr.get(i) == i);
        }
    }
}

TEST_CASE("pop_back", "[resize]") {
    ResizeableArray<int> arr;
    for (int i = 0; i < 5; ++i) arr.push_back(i);

    SECTION("pop_back returns elements in reverse order") {
        for (int i = 4; i >= 0; --i) {
            REQUIRE(arr.pop_back() == i);
        }
        REQUIRE(arr.empty());
    }

    SECTION("pop_back on empty array throws") {
        ResizeableArray<int> emptyArr;
        REQUIRE_THROWS_AS(emptyArr.pop_back(), std::out_of_range);
    }
}

TEST_CASE("get method", "[resize]") {
    ResizeableArray<int> arr;
    for (int i = 0; i < 5; ++i) arr.push_back(i);

    SECTION("valid indices") {
        for (int i = 0; i < 5; ++i) {
            REQUIRE(arr.get(i) == i);
        }
    }

    SECTION("out-of-bounds indices throw") {
        REQUIRE_THROWS_AS(arr.get(-1), std::out_of_range);
        REQUIRE_THROWS_AS(arr.get(5), std::out_of_range);
    }
}

TEST_CASE("set method", "[resize]") {
    ResizeableArray<int> arr;
    for (int i = 0; i < 5; ++i) arr.push_back(i);

    SECTION("replace elements at valid indices") {
        arr.set(2, 99);
        REQUIRE(arr.get(2) == 99);
    }

    SECTION("out-of-bounds indices throw") {
        REQUIRE_THROWS_AS(arr.set(-1, 42), std::out_of_range);
        REQUIRE_THROWS_AS(arr.set(5, 42), std::out_of_range);
    }
}

TEST_CASE("insert method", "[resize]") {
    ResizeableArray<int> arr;
    for (int i = 0; i < 3; ++i) arr.push_back(i); // [0,1,2]

    SECTION("insert at beginning") {
        arr.insert(0, 99); // [99,0,1,2]
        REQUIRE(arr.size() == 4);
        REQUIRE(arr.get(0) == 99);
    }

    SECTION("insert in middle") {
        arr.insert(1, 88); // [0,88,1,2]
        REQUIRE(arr.size() == 4);
        REQUIRE(arr.get(1) == 88);
    }

    SECTION("insert at end") {
        arr.insert(arr.size(), 77); // [0,1,2,77]
        REQUIRE(arr.size() == 4);
        REQUIRE(arr.get(3) == 77);
    }

    SECTION("insert out-of-bounds throws") {
        REQUIRE_THROWS_AS(arr.insert(-1, 5), std::out_of_range);
        REQUIRE_THROWS_AS(arr.insert(10, 5), std::out_of_range);
    }
}

TEST_CASE("remove method", "[resize]") {
    ResizeableArray<int> arr;
    for (int i : {1, 2, 3, 2, 4}) arr.push_back(i); // [1,2,3,2,4]

    SECTION("remove first occurrence") {
        arr.remove(2); // remove first 2: [1,3,2,4]
        REQUIRE(arr.size() == 4);
        REQUIRE(arr.get(0) == 1);
        REQUIRE(arr.get(1) == 3);
    }

    SECTION("remove element not present") {
        arr.remove(99); // no-op
        REQUIRE(arr.size() == 5);
    }

    SECTION("remove all elements one by one") {
        arr.remove(1);
        arr.remove(2);
        arr.remove(3);
        arr.remove(2);
        arr.remove(4);
        REQUIRE(arr.empty());
    }
}

TEST_CASE("empty method", "[resize]") {
    ResizeableArray<int> arr;
    REQUIRE(arr.empty());

    arr.push_back(1);
    REQUIRE_FALSE(arr.empty());

    arr.pop_back();
    REQUIRE(arr.empty());
}
