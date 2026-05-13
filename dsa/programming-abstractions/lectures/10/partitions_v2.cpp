#include <iostream>
#include "console.h"
#include "vector.h"
using namespace std;

// We could modify our isPartitionable() function to keep track of the actual partition vectors being created, 
// rather than just tracking the sums of the elements we would have placed in those vectors.

// Returns sum of all elements in a vector of ints.
int vecSum(Vector<int>& v)
{
    int sum = 0;

    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    
    return sum;
}

// v is the vector of (remaining) elements we have to choose from. sum1 and sum2
// are the sums we have so far for the two (hypothetical) vectors the elements
// are being partitioned into.
bool isPartitionable(Vector<int>& v, Vector<int>& v1, Vector<int>& v2)
{
    if(v.isEmpty())
    {
        int sum1 = vecSum(v1);
        int sum2 = vecSum(v2);

        if (sum1 == sum2)
        {
            cout << "v1: " << v1 << endl;
            cout << "v2: " << v2 << endl;
        }
        return sum1 == sum2;
    }

    // Pull first element out of our source vector.
    int thisOne = v[0];
    v.remove(0);

    // Choose, explore, unchoose! We add thisOne to v1 rather than v2 and see if this
    // leads to a solution. We then need to remove thisOne from v1 before making the
    // other choice (adding it to v2). Otherwise, the element will be in both vectors.
    v1.add(thisOne);
    bool result1 = isPartitionable(v, v1, v2);
    v1.remove(v1.size() - 1);

    // Choose, explore, unchoose! We now add thisOne to v2 and check whether that leads
    // to a solution. After exploring, we need to remove thisOne from v2. Otherwise, it
    // will linger there as we return to previous calls that never added it to v2.
    v2.add(thisOne);
    bool result2 = isPartitionable(v, v1, v2);
    v2.remove(v2.size() - 1);

    // We need to place thisOne back in v so we aren't destroying the input vector as
    // a side effect of solving this problem.
    v.insert(0, thisOne);

    return result1 || result2;

}

bool isPartitionable(Vector<int>& v)
{
    Vector<int> v1;
    Vector<int> v2;
    return isPartitionable(v, v1, v2);
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

/*
Notice that our first approach to isPartitionable returns true as soon as it finds a solution and halts any further exploration! 
This is a common backtracking idiom that you must be familiar with. 

Note also that the second approach to isPartitionable -- the one that keeps track of the vector contents and not just the sums -- 
does not benefit from this early termination. If making one recursive call, it always makes the second recursive call, as well. 
Modifying this function to avoid making that second call unnecessarily is one of today's exam prep questions.
*/