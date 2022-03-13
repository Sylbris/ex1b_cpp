/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Dan "Sylbris" Davydov
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {

    //col > row
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
    CHECK(nospaces(mat(9, 3, '&', '*')) == nospaces("&&&&&&&&&\n&*******&\n&&&&&&&&&"));
    CHECK(nospaces(mat(7, 5, '@', '%')) == nospaces("@@@@@@@\n@%%%%%@\n@%@@@%@\n@%%%%%@\n@@@@@@@"));

    //col < row
    CHECK(nospaces(mat(3, 7, '$', '-')) == nospaces("$$$\n$-$\n$-$\n$-$\n$-$\n$-$\n$$$"));
    CHECK(nospaces(mat(5, 9, '^', '#')) == nospaces("^^^^^\n^###^\n^#^#^\n^#^#^\n^#^#^\n^#^#^\n^#^#^\n^###^\n^^^^^"));
    CHECK(nospaces(mat(7, 15, ')', '(')) == nospaces(")))))))\n)((((()\n)()))()\n)()()()\n)()()()\n)()()()\n)()()()\n)()()()\n)()()()\n)()()()\n)()()()\n)()()()\n)()))()\n)((((()\n)))))))"));

    //Check difference between different mats.
    CHECK(nospaces(mat(3, 7, '$', '-')) != nospaces(mat(7, 3, '$', '-')));
    CHECK(nospaces(mat(5, 3, '(', ')')) != nospaces(mat(5, 3, ')', '(')));

    //Checking different sizes.
    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));
    CHECK(nospaces(mat(5, 1, '@', '-')) == nospaces("@@@@@"));
    CHECK(nospaces(mat(1, 5, '@', '-')) == nospaces("@\n@\n@\n@\n@\n"));
    
    //Check size of big mats.
    CHECK(nospaces(mat(151, 151, '@', '-')).length() == 22801);
    CHECK(nospaces(mat(15, 13, '@', '-')).length() == nospaces(mat(13, 15, '@', '-')).length());

    
}

TEST_CASE("Bad input") {
    //Check col even
    CHECK_THROWS(mat(10, 5, '$', '%'));
    //Check row even
    CHECK_THROWS(mat(9, 4, '$', '%'));
    //Check invalid col +row
    CHECK_THROWS(mat(-1, 2, '$', '%'));
    CHECK_THROWS(mat(3, -1, '$', '%'));
    CHECK_THROWS(mat(0, 0, '$', '%'));

    //Check spaces input.
    char spaces [] = {' ', '\t' , '\n' , '\v', '\f' , '\r'};
    int i = 0;
    for(i=0; i<6; i++){
        char sym = spaces[i];
        CHECK_THROWS(mat(3, 5, sym, '*'));
        CHECK_THROWS(mat(9, 7, '%', sym));
    }

    
}
