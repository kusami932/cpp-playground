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

// Write a pass-by-pointer function named sameValue() that takes two integer pointers 
// and determines whether those are pointers to the same value in memory. 
// If so, return true. Otherwise, return false
bool sameValue(int *p, int *q)
{
    // We must dereference both q and p to determine     
    // whether they point to the same value. It is       
    // possible for them both to point to the same value 
    // even if they point to different addresses in      
    // memory (as seen in the test case above where      
    // sameValue(&a, &b) is expected to return true.     
    return *p == *q;
}

PROVIDED_TEST("simple samePlace and sameValue test")
{
    int a = 11;
    int b = 11;
    int c = 32;

    EXPECT_EQUAL(samePlace(&a, &b), false);
    EXPECT_EQUAL(samePlace(&b, &b), true);
    EXPECT_EQUAL(sameValue(&a, &b), true);
    EXPECT_EQUAL(sameValue(&b, &b), true);
    EXPECT_EQUAL(sameValue(&b, &c), false);
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}                                              