#include <iostream>
#include "console.h"
#include "SimpleTest.h"
using namespace std;

bool isPalindrome(string s)
{
    // All strings of length 1 are palindromes, as is the empty string.
    if (s.length() <= 1)
    {
        return true;
    }

    if (s[0] != s[s.length() - 1])
    {
        return false;
    }

    // Peel off the first and last character and pass the remaining string
    // to isPalindrome() recursively. We needn't use a new string variable
    // here. I did that in class only to clarify what was going on. The
    // more conventional approach is to pass s.substr(...) to isPalindrome()
    // directly.
    string sub = s.substr(1, s.length() - 2);
    return isPalindrome(sub);
}

PROVIDED_TEST("various palindromes")
{
    EXPECT_EQUAL(isPalindrome("racecar"), true);
    EXPECT_EQUAL(isPalindrome("kayak"), true);
    EXPECT_EQUAL(isPalindrome("civic"), true);
    EXPECT_EQUAL(isPalindrome("radar"), true);
    EXPECT_EQUAL(isPalindrome("rotor"), true);
    EXPECT_EQUAL(isPalindrome("step on no pets"), true);
    EXPECT_EQUAL(isPalindrome("b"), true);
    EXPECT_EQUAL(isPalindrome(""), true);
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}