/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Aldrarga ahmad>
 *
 * Date: 2021-03
 */

#include "doctest.h"
#include "mat.hpp"

#include <string>
#include <algorithm>
using namespace std;
using namespace ariel;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input")
{
    CHECK(nospaces(ariel::mat(1, 1, '@', '-')) == nospaces("@"));
    CHECK(nospaces(ariel::mat(0, 0, '@', '-')) == nospaces(""));
    CHECK(nospaces(ariel::mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                           "@-------@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-@---@-@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-------@\n"
                                                           "@@@@@@@@@"));
    CHECK(nospaces(ariel::mat(13, 7, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                            "@-----------@\n"
                                                            "@-@@@@@@@@@-@\n"
                                                            "@-@-------@-@\n"
                                                            "@-@@@@@@@@@-@\n"
                                                            "@-----------@\n"
                                                            "@@@@@@@@@@@@@"));
    CHECK(nospaces(ariel::mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                           "$+$\n"
                                                           "$+$\n"
                                                           "$+$\n"
                                                           "$$$"));

    CHECK(nospaces(ariel::mat(13, 9, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                            "@ -----------@\n"
                                                            "@ -@@@@@@@@@-@\n"
                                                            "@ -@-------@-@\n"
                                                            "@ -@-@@@@@-@-@\n"
                                                            "@ -@-------@-@\n"
                                                            "@ -@@@@@@@@@-@\n"
                                                            "@ -----------@\n"
                                                            "@ @@@@@@@@@@@@"));

    CHECK(nospaces(ariel::mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                           "@-------@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-@---@-@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-------@\n"
                                                           "@@@@@@@@@"));
    /* Add more test here */
}

TEST_CASE("Bad input")
{
    CHECK(nospaces(ariel::mat(1, 1, '@', '-')) == nospaces("@@@@@@@"));
    CHECK(nospaces(ariel::mat(0, 0, '@', '-')) == nospaces("@"));
    CHECK(nospaces(ariel::mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                           "@-@@@@@@-@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-@---@-@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-@@@@@@--@\n"
                                                           "@@@@@@@@@"));
    CHECK(nospaces(ariel::mat(13, 7, '@', '-')) == nospaces("@@@@@------@@@@@\n"
                                                            "@-----------@\n"
                                                            "@-@@@------@@@-@\n"
                                                            "@-@-------@-@\n"
                                                            "@-@@@------@@@-@\n"
                                                            "@-----------@\n"
                                                            "@@@@------@@@@@"));
    CHECK(nospaces(ariel::mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                           "$+$\n"
                                                           "$+$\n"
                                                           "$$$\n"
                                                           "$$$"));

    CHECK(nospaces(ariel::mat(13, 9, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                            "@ -----------@\n"
                                                            "@ -@@@@@@@@@-@\n"
                                                            "@ -@@@@@@@@-@\n"
                                                            "@ -@-@@@@@-@-@\n"
                                                            "@ -@@@@@@@@-@\n"
                                                            "@ -@@@@@@@@@-@\n"
                                                            "@ -----------@\n"
                                                            "@ @@@@@@@@@@@@"));

    CHECK(nospaces(ariel::mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                           "@-------@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-@---@-@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-------@\n"
                                                           "@@@@@@@@@"));
    /* Add more test here */
}

TEST_CASE("even input")
{

    CHECK_THROWS(ariel::mat(0, 0, '$', '%'));
    CHECK_THROWS(ariel::mat(10, 5, '$', '%'));
    CHECK_THROWS(ariel::mat(8, 3, '$', '+'));
    CHECK_THROWS(ariel::mat(20, 13, '$', '+'));
    CHECK_THROWS(ariel::mat(18, 23, '$', '%'));
    CHECK_THROWS(ariel::mat(2, 33, '$', '+'));
    CHECK_THROWS(ariel::mat(22, 53, '$', '-'));
    CHECK_THROWS(ariel::mat(16, 83, '$', '+'));
    CHECK_THROWS(ariel::mat(6, 35, '#', '-'));
    CHECK_THROWS(ariel::mat(4, 39, '#', '+'));
    CHECK_THROWS(ariel::mat(8, 73, '#', '+'));
    CHECK_THROWS(ariel::mat(20, 95, '#', '+'));
}
TEST_CASE("negative input")
{
    CHECK_THROWS(ariel::mat(-10, -5, '$', '%'));
    CHECK_THROWS(ariel::mat(-9, -3, '$', '%'));
    CHECK_THROWS(ariel::mat(-19, -13, '$', '%'));
    CHECK_THROWS(ariel::mat(-17, -23, '$', '%'));
    CHECK_THROWS(ariel::mat(-23, -33, '$', '%'));
    CHECK_THROWS(ariel::mat(-21, -53, '$', '%'));
    CHECK_THROWS(ariel::mat(-15, -83, '$', '%'));
}

TEST_CASE("Bad syntax")
{
    CHECK_THROWS(ariel::mat(8, 5, 5, 5));
    CHECK_THROWS(ariel::mat('@', '@', '$', '$'));
    CHECK_THROWS(ariel::mat('#', '#', 4, 5));
    CHECK_THROWS(ariel::mat('0', '7', '2', '$'));
    CHECK_THROWS(ariel::mat('8', '8', '5', '5'));
}
