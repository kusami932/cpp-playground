#include <iostream>
#include "console.h"
#include "SimpleTest.h"
#include "vector.h"
using namespace std;

/*
Behind the Scenes with v.insert(index, value) 

The runtime of v.insert(index, value) can be as bad as O(n). That happens when we insert a value at the beginning of 
our vector, because all n elements in the vector need to scooch over to make room for the new one. That also happens 
if we insert into the middle of a vector with n elements. In that case, we have to scooch over n/2 elements, which is 
O(n). (There, I'm rewriting n/2 in my head as (1/2)n and then dropping the constant coefficient of (1/2) to get the 
big-oh notation.)

But if we insert immediately after the last element in a vector, we only have to do one write operation 
(no elements get scooched over!), which is almost always going to be an O(1) operation. 
*/


Vector<int> insertAtEnd(int n)
{
    Vector<int> v;
    for (int i = 0; i < n i++)
    {
        v.insert(i, i);
    }
    return v;
}

PROVIDED_TEST("runtime comparison")
{
    int size;

    size = 20000;
    TIME_OPERATION(size, insertAtEnd(size));

    size = 40000;
    TIME_OPERATION(size, insertAtEnd(size));

    size = 80000;
    TIME_OPERATION(size, insertAtEnd(size));

    size = 160000;
    TIME_OPERATION(size, insertAtEnd(size));

    size = 320000;
    TIME_OPERATION(size, insertAtEnd(size));

    size = 640000;
    TIME_OPERATION(size, insertAtEnd(size));
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}

// vector.insert(index, value) isn't necessarily always O(n). 
// It is more expensive to insert at the beginning of a vector than at the end. 