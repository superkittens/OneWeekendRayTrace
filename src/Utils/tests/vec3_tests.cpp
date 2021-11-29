#define CATCH_CONFIG_MAIN

//  Utils tests

#include "catch.hpp"
#include "vec3.h"
#include <tuple>
#include <cmath>

//  Vec3 test cases
TEST_CASE("Vec3 Access Tests")
{
    vec3 vec;
    auto point = std::make_tuple(0.0, 1.0, 2.0);

    vec[0] = std::get<0>(point);
    vec[1] = std::get<1>(point);
    vec[2] = std::get<2>(point);

    SECTION("Array subscript test")
    {
        REQUIRE(vec[0] == std::get<0>(point));
        REQUIRE(vec[1] == std::get<1>(point));
        REQUIRE(vec[2] == std::get<2>(point));
    }

    SECTION("Get methods tests")
    {
        REQUIRE(vec.x() == std::get<0>(point));
        REQUIRE(vec.y() == std::get<1>(point));
        REQUIRE(vec.z() == std::get<2>(point));
    }
}

TEST_CASE("vec3 Arithmetic Tests")
{
    auto pointA = std::make_tuple(1.0, 2.0, 3.0);
    auto pointB = std::make_tuple(4.0, 5.0, 6.0);
    auto scale = 2.0;

    auto vecA = vec3(std::get<0>(pointA), std::get<1>(pointA), std::get<2>(pointA));
    auto vecB = vec3(std::get<0>(pointB), std::get<1>(pointB), std::get<2>(pointB));

    SECTION("+= Operator")
    {
        auto resultVec = vecA + vecB;

        REQUIRE(resultVec.x() == std::get<0>(pointA) + std::get<0>(pointB));
        REQUIRE(resultVec.y() == std::get<1>(pointA) + std::get<1>(pointB));
        REQUIRE(resultVec.z() == std::get<2>(pointA) + std::get<2>(pointB));
    }

    SECTION("Scale operator")
    {
        vecA *= scale;

        REQUIRE(vecA.x() == std::get<0>(pointA) * scale);
        REQUIRE(vecA.y() == std::get<1>(pointA) * scale);
        REQUIRE(vecA.z() == std::get<2>(pointA) * scale);

        auto resultVec = vecB * scale;

        REQUIRE(resultVec.x() == std::get<0>(pointB) * scale);
        REQUIRE(resultVec.y() == std::get<1>(pointB) * scale);
        REQUIRE(resultVec.z() == std::get<2>(pointB) * scale);
    }

    SECTION("Divide operator")
    {
        vecA /= scale;

        REQUIRE(vecA.x() == std::get<0>(pointA) / scale);
        REQUIRE(vecA.y() == std::get<1>(pointA) / scale);
        REQUIRE(vecA.z() == std::get<2>(pointA) / scale);

        auto resultVec = vecB / scale;

        REQUIRE(resultVec.x() == std::get<0>(pointB) / scale);
        REQUIRE(resultVec.y() == std::get<1>(pointB) / scale);
        REQUIRE(resultVec.z() == std::get<2>(pointB) / scale);
    }

    SECTION("+ Operator")
    {
        auto resultVec = vecA + vecB;

        REQUIRE(resultVec.x() == std::get<0>(pointA) + std::get<0>(pointB));
        REQUIRE(resultVec.y() == std::get<1>(pointA) + std::get<1>(pointB));
        REQUIRE(resultVec.z() == std::get<2>(pointA) + std::get<2>(pointB));
    }

    SECTION("- Operator")
    {
        auto resultVec = vecA - vecB;

        REQUIRE(resultVec.x() == std::get<0>(pointA) - std::get<0>(pointB));
        REQUIRE(resultVec.y() == std::get<1>(pointA) - std::get<1>(pointB));
        REQUIRE(resultVec.z() == std::get<2>(pointA) - std::get<2>(pointB));
    }

    SECTION("* Operator")
    {
        auto resultVec = vecA * vecB;

        REQUIRE(resultVec.x() == std::get<0>(pointA) * std::get<0>(pointB));
        REQUIRE(resultVec.y() == std::get<1>(pointA) * std::get<1>(pointB));
        REQUIRE(resultVec.z() == std::get<2>(pointA) * std::get<2>(pointB));
    }

    SECTION("Dot Product")
    {
        auto dotProduct = dot(vecA, vecB);

        REQUIRE(dotProduct ==   std::get<0>(pointA) * std::get<0>(pointB) +
                                std::get<1>(pointA) * std::get<1>(pointB) +
                                std::get<2>(pointA) * std::get<2>(pointB));
    }

    SECTION("Cross Product")
    {
        auto resultVec = cross(vecA, vecB);

        REQUIRE(resultVec.x() == std::get<1>(pointA) * std::get<2>(pointB) - std::get<2>(pointA) * std::get<1>(pointB));
        REQUIRE(resultVec.y() == std::get<2>(pointA) * std::get<0>(pointB) - std::get<0>(pointA) * std::get<2>(pointB));
        REQUIRE(resultVec.z() == std::get<0>(pointA) * std::get<1>(pointB) - std::get<1>(pointA) * std::get<0>(pointB));
    }
}

TEST_CASE("vec3 Length Tests")
{
    constexpr double A = 1.0;
    constexpr double B = 2.0;
    constexpr double C = 3.0;
    constexpr double EXPECTED_LENGTH_SQ = A * A + B * B + C * C;
    const double EXPECTED_LENGTH = std::sqrt(EXPECTED_LENGTH_SQ);

    auto vec = vec3(A, B, C);

    REQUIRE(vec.length_squared() == EXPECTED_LENGTH_SQ);
    REQUIRE(vec.length() == EXPECTED_LENGTH);
}

TEST_CASE("Unit Vector")
{
    constexpr double A = 1.0;
    constexpr double B = 2.0;
    constexpr double C = 3.0;
    auto vec = vec3(A, B, C);

    auto vectorLength = vec.length();
    auto unitVector = unit_vector(vec);

    REQUIRE(unitVector.x() == A / vectorLength);
    REQUIRE(unitVector.y() == B / vectorLength);
    REQUIRE(unitVector.z() == C / vectorLength);
}
