
#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace ariel;

string nonspace(string s) {

    for(int i=0 ; i<s.length() ; i++)
    {
        if(s[i]=='\n' || s[i]==' ' || s[i]=='\t' || s[i]=='\r')
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
    return s;

}

TEST_CASE("Good snowman code:") {

    CHECK(nonspace(snowman(11111111)) == string("_===_(.,.)<(:)>(:)"));
    CHECK(nonspace(snowman(22222222)) == string("___.....\\(o.o)/(][)(\"\")"));
    CHECK(nonspace(snowman(33333333)) == string("_/_\\(O_O)/(><)\\(___)"));
    CHECK(nonspace(snowman(44444444)) == string("___(_*_)(--)()()"));
    CHECK(nonspace(snowman(12341234)) == string("_===_(O.-)/<(><)()"));
    CHECK(nonspace(snowman(43214321)) == string("___(_*_)(o_.)(][)\\(:)"));
    CHECK(nonspace(snowman(12121212)) == string("_===_(..o)/<(:)(\"\")"));
    CHECK(nonspace(snowman(34343434)) == string("_/_\\(O-)/(><)()"));
    CHECK(nonspace(snowman(12344321)) == string("_===_(O.-)(][)\\(:)"));
    CHECK(nonspace(snowman(11223344)) == string("_===_(o,o)/()\\()"));
  
}

TEST_CASE("Bad snowman code:") {

    CHECK_THROWS(snowman(51111111));
    CHECK_THROWS(snowman(26222222));
    CHECK_THROWS(snowman(33733333));
    CHECK_THROWS(snowman(44484444));
    CHECK_THROWS(snowman(11119111));
    CHECK_THROWS(snowman(22222022));
    CHECK_THROWS(snowman(33333353));
    CHECK_THROWS(snowman(44444446));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(22));
    CHECK_THROWS(snowman(333));
    CHECK_THROWS(snowman(4444));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(222222));
    CHECK_THROWS(snowman(3333333));
    CHECK_THROWS(snowman(444444444));
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(-22222222));
    CHECK_THROWS(snowman(-33333333));
    CHECK_THROWS(snowman(-44444444));

}

