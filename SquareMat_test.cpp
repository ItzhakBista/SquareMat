//itzhak173@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <cassert>
#include <iostream>

using namespace MatOps;

TEST_CASE("Testing Constructors") {
    SUBCASE("Default constructor") {
        SquareMat m1(2);
        CHECK(m1[0][0] == 0.0);
        CHECK(m1[0][1] == 0.0);
        CHECK(m1[1][0] == 0.0);
        CHECK(m1[1][1] == 0.0);
    }
    
    SUBCASE("Constructor with value") {
        SquareMat m2(2, 5.0);
        CHECK(m2[0][0] == 5.0);
        CHECK(m2[0][1] == 5.0);
        CHECK(m2[1][0] == 5.0);
        CHECK(m2[1][1] == 5.0);
    }
    
    SUBCASE("Copy constructor") {
        SquareMat m2(2, 5.0);
        SquareMat m3(m2);
        CHECK(m3[0][0] == 5.0);
        CHECK(m3[0][1] == 5.0);
        CHECK(m3[1][0] == 5.0);
        CHECK(m3[1][1] == 5.0);
    }
}

TEST_CASE("Testing Arithmetic Operators") {
    SquareMat m1(2, 2.0);
    SquareMat m2(2, 3.0);
    
    SUBCASE("Addition") {
        SquareMat m3 = m1 + m2;
        CHECK(m3[0][0] == 5.0);
        CHECK(m3[0][1] == 5.0);
        CHECK(m3[1][0] == 5.0);
        CHECK(m3[1][1] == 5.0);
    }
    
    SUBCASE("Subtraction") {
        SquareMat m4 = m2 - m1;
        CHECK(m4[0][0] == 1.0);
        CHECK(m4[0][1] == 1.0);
        CHECK(m4[1][0] == 1.0);
        CHECK(m4[1][1] == 1.0);
    }
    
    SUBCASE("Matrix Multiplication") {
        SquareMat m5(2);
        m5[0][0] = 1; m5[0][1] = 2;
        m5[1][0] = 3; m5[1][1] = 4;
        
        SquareMat m6(2);
        m6[0][0] = 5; m6[0][1] = 6;
        m6[1][0] = 7; m6[1][1] = 8;
        
        SquareMat m7 = m5 * m6;
        CHECK(m7[0][0] == 19);
        CHECK(m7[0][1] == 22);
        CHECK(m7[1][0] == 43);
        CHECK(m7[1][1] == 50);
    }
}

TEST_CASE("Testing Other Operators") {
    SquareMat m1(2);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;
    
    SUBCASE("Unary Minus") {
        SquareMat m2 = -m1;
        CHECK(m2[0][0] == -1);
        CHECK(m2[0][1] == -2);
        CHECK(m2[1][0] == -3);
        CHECK(m2[1][1] == -4);
    }
    
    SUBCASE("Transpose") {
        SquareMat m3 = ~m1;
        CHECK(m3[0][0] == 1);
        CHECK(m3[0][1] == 3);
        CHECK(m3[1][0] == 2);
        CHECK(m3[1][1] == 4);
    }
    
    SUBCASE("Determinant") {
        CHECK(!m1 == doctest::Approx(1*4 - 2*3));
    }
}

TEST_CASE("Testing Comparison Operators") {
    SquareMat m1(2, 2.0);
    SquareMat m2(2, 3.0);
    
    CHECK(m1 == m1);
    CHECK(m1 != m2);
    CHECK(m1 < m2);
    CHECK(m2 > m1);
    CHECK(m1 <= m2);
    CHECK(m2 >= m1);
}