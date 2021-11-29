#include "catch.hpp"
#include "vec3.h"
#include "ray.h"

TEST_CASE("Ray Initialization")
{
    const point3    ORIGIN = point3(0, 0, 0);
    const vec3      DIRECTION = vec3(1, 1, 1);

    auto ray0 = ray(ORIGIN, DIRECTION);
    
    REQUIRE(ray0.origin() == ORIGIN);
    REQUIRE(ray0.direction() == DIRECTION);
}

TEST_CASE("Get Point Along Ray")
{
    const point3    ORIGIN = point3(0, 0, 0);
    const vec3      DIRECTION = vec3(1, 1, 1);
    constexpr double t = 2.0;

    auto ray0 = ray(ORIGIN, DIRECTION);

    REQUIRE(ray0.at(t) == ORIGIN + (t * DIRECTION));
}