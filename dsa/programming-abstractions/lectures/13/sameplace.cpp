#include <iostream>
#include "console.h"
#include "SimpleTest.h"
using namespace std;

// Write a pass-by-pointer function named samePlace() that takes two integer pointers 
// and determines whether those are pointers to the same place in memory. 
// If so, return true. Otherwise, return false

// You should be able to infer the parameter types for this function
// from the way this function is called from the provided test.
bool samePlace(int *p, int *q)
{
    // The values p and q hold are memory addresses. 
    // We simply check whether the two addresses     
    // they contain are the same -- i.e., whether    
    // p is equal to q.                         
    return p == q;
}

PROVIDED_TEST("simple samePlace test")
{
    int a = 11;
    int b = 11;
    int c = 32;

    EXPECT_EQUAL(samePlace(&a, &b), false);
    EXPECT_EQUAL(samePlace(&b, &b), true);
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}                                              