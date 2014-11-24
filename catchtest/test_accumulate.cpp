#include <accumulate.hpp>
#include "helpers.hpp"

#include <vector>
#include <iterator>
#include <string>

#include "catch.hpp"

using iter::accumulate;
using itertest::BasicIterable;

using Vec = const std::vector<int>;
TEST_CASE("Simple sum", "[accumulate]") {
    Vec ns{1,2,3,4,5};
    auto a = accumulate(ns);

    Vec v(std::begin(a), std::end(a));
    Vec vc{1,3,6,10,15};
    REQUIRE( v == vc );
}

TEST_CASE("With subtraction lambda", "[accumulate]") {
    Vec ns{5,4,3,2,1};
    auto a = accumulate(ns, [](int a, int b){return a - b; });

    Vec v(std::begin(a), std::end(a));
    Vec vc{5, 1, -2, -4, -5};
    REQUIRE( v == vc );
}

TEST_CASE("initializer_list works", "[accumulate]") {
    auto a = accumulate({1, 2, 3});
    Vec v(std::begin(a), std::end(a));
    Vec vc{1, 3, 6};

    REQUIRE( v == vc );
}

TEST_CASE("binds reference when it should", "[enumerate]") {
    BasicIterable<int> bi{1, 2};
    accumulate(bi);
    REQUIRE_FALSE( bi.was_moved_from() );
}

TEST_CASE("moves rvalues into enumerable object", "[enumerate]") {
    BasicIterable<int> bi{1, 2};
    accumulate(std::move(bi));
    REQUIRE( bi.was_moved_from() );
}
