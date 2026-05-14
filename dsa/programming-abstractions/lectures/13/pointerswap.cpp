#include <iostream>
#include "console.h"
#include "SimpleTest.h"
using namespace std;

// Use pointers to write a swap() function that takes the addresses of two variables and then swaps their values. 
// By passing addresses to a function, you can use them to modify variables you created back in your calling function
void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

PROVIDED_TEST("Simple test of swap() function.")
{
    int i = 56;
    int j = 88787;

    // Notice that we're giving the addresses of i and j to the
    // swap() function. That will enable swap() to change the
    // values of i and j from outside of this test case()!
    swap(&i, &j);
    EXPECT_EQUAL(88787, i);
    EXPECT_EQUAL(j, 56);
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}