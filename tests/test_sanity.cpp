#include <catch2/catch_test_macros.hpp>

// Placeholder test to validate the build/test/CI pipeline end-to-end before
// any real matching engine logic lands. Replace/expand once the order book
// core is implemented.
TEST_CASE("build pipeline sanity check", "[sanity]") {
    REQUIRE(1 + 1 == 2);
}
