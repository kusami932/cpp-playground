#include <iostream>
#include "console.h"
#include "vector.h"
using namespace std;
/*
Recursive Backtracking Solution (1 of 3)

Below is the first backtracking solution we constructed for the knapsack problem. This one 
follows a common paradigm we've seen where we have a container (often called rest, but in 
this case called treasures) from which we remove elements as we descend deeper and deeper 
into our recursive calls. We hit our base case when the container we're choosing from is empty.

Note that this is a pass-by-reference solution, which means that we must add elements 
back to our vector after making our recursive calls for two reasons:

Firstly, when we hit our first base case, our vector of treasures will be empty. If we never 
add anything back to that vector, then when we return to previous calls and start exploring 
other recursive branches of our problem space, there will never be any treasures to choose from. 
We need to add those treasures back so we can make our take-or-don't-take choices in other branches of the tree.

Secondly, it's tremendously disruptive for us to destroy the contents of an input parameter over the course of solving some problem. 
The person who calls a function like this might still have use for the data they passed to us after the function is finished, so we 
need to be sure to restore values to the vector in question as we return our way out of this function.
*/

// Returns the maximum value we can derive by taking treasures from the given vector
// (without the total weight of the treasures we take exceeding the given capacity).
int knapsack(Vector<treasureT>& treasures, int capacity)
{
    // No more treasures to choose from means no more value to gain. Finito!
    if(treasures.size() == 0)
    {
        return 0;
    }

    // Here, we pull an item out of our vector in preparation for making a binary
    // choice about what to do with it: either take it or leave it behind.

    // Removing from (and later adding to) the last position in our vector is more
    // efficient than operating on index 0 (zero). The latter requires us to scooch
    // over all the rest of the elements in the vector.
    treasureT thisOne = treasures[treasures.size() - 1];
    treasures.remove(treasures.size() - 1);

    int result;

    if(thisOne.weight <= capacity)
    {
        // Take it. Adding the current item to our knapsack adds to our running value
        // but also reduces the capacity of our knapsack.
        int with = thisOne.value + knapsack(treasures, capacity - thisOne.weight);

        // Don't take it. Leaving this item behind in hopes of finding other, better
        // items with which to fill our knapsack means we don't gain any value, but
        // we also don't reduce the capacity of our knapsack.
        int without = knapsack(treasures, capacity);

        result = max(with, without);
    }
    else 
    {
        // Don't take it. This is the branch where thisOne is too heavy to take. So,
        // we don't have the luxury of making a binary choice about whether to take
        // the item with us. We must leave it behind.
        result = knapsack(treasures, capacity);
    }

    // Unchoose. See notes above this function about why we must add this back.
    treasures.add(thisOne);
    return result;
}