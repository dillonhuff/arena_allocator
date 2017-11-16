#include "arena_allocator.h"

#define CATCH_CONFIG_MAIN

#include "catch.hpp"


namespace arena_alloc {

  TEST_CASE("Allocate and call") {
    arena_allocator a(23400);

    SECTION("All memory is available initially") {
      REQUIRE(a.get_size_left() == 23400);
    }

    SECTION("Allocated values can be used") {
      int* val = a.allocate<int>();
      *val = 23;

      REQUIRE(*val == 23);
    }

    SECTION("After allocation less space is left") {
      int* val = a.allocate<int>();
      *val = 23;

      REQUIRE(a.get_size_left() == (23400 - sizeof(int)));
    }

  }
}
