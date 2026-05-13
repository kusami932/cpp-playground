#include <iostream>
#include "console.h"
#include "vector.h"
using namespace std;

/*
The next problem I presented was the following: Is it possible to partition some vector, V, into two vectors, V1 and V2, 
such that the sum of the elements in V1 is equal to the sum of the elements in V2? Recall that to be considered a partition, 
each element from V must occur in exactly one of the vectors V1 or V2. We neither include an element from V in both V1 and V2 
nor exclude an element in V from both of those vectors.

For example, if V = {1, 1, 2, 3, 5}, we can partition the elements into V1 = {1, 5} and V2 = {1, 2, 3}. 
The elements in V1 sum to 6, as do the elements in V2.

The elements in V = {1, 4, 5, 6}, however, cannot be partitioned in such a fashion.
*/

// v is the vector of (remaining) elements we have to choose from. sum1 and sum2
// are the sums we have so far for the two (hypothetical) vectors the elements
// are being partitioned into.
bool isPartitionable(Vector<int>& v, int sum1, int sum2)
{
    if(v.isEmpty())
    {
        return sum1 == sum2;
    }

    // Pull first element out of vector.
    int thisOne = v[0];
    v.remove(0);

    // Below, the first recursive call adds thisOne to first vector sum rather than
    // second vector sum. The second recursive call instead adds thisOne to the second
    // vector sum.
    bool result = isPartitionable(v, sum1 + thisOne, sum2) ||
                  isPartitionable(v, sum1 , sum2 + thisOne);

    // We must undo the state change where thisOne was removed from v so that when
    // we return to previous calls and make different decisions regarding which
    // vector earlier elements went into, we can then come back to this one and
    // decide where it goes in different branches of our decision tree.
    v.insert(0, thisOne);
    return result;
}

bool isPartitionable(Vector<int>& v)
{
    return isPartitionable(v, 0, 0);
}

int main()
{
    Vector<int> v;

    v = {1, 1, 2, 3, 5};
    cout << isPartitionable(v) << endl;  // true

    v = {1, 4, 5, 6};
    cout << isPartitionable(v) << endl;  // false

    return 0;
}
