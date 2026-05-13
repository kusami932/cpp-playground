/*
Recursive Backtracking Solution (2 of 3)

The second recursive solution we examined introduced a new variable, k, that started at 0 (zero) and worked its way 
up through our vector. I mentioned that with this sort of approach, there are often two ways to interpret the auxiliary 
integer variable, and that both interpretations effectively mean the same thing; they're just two sides of the same coin. 
In this particular example, k can be interpreted as follows:

Within this call, we will consider what to do with the item at index k in the vector.
We have already made decisions about what to do with the first k items in the vector.
If k starts at zero, then we will have made decisions about all items in the vector and hit a base case when k == treasures.size().

A key advantage of this approach is that we don't need to do any of the bookkeeping associated with adding or removing 
items from our treasures vector. We still pass it by reference, which means we benefit from the time and space savings 
compared to passing it by value. The only downside here is that we need to develop a solid understanding of the purpose of that k variable.
*/

// Returns the maximum value we can derdive by taking treasures from the given vector
// (without the total weight of the treasures we take exceeding the given capacity),
// focusing only on indices k and beyond.
int knapsack(Vector<treasureT>& treasures, int capacity, int k)
{
    // No more treasures to choose from means no more value to gain. Finito!
    if (k == treasures.size())
    {
        return 0;
    }

    // The structure below is very similar to that of today's first solution.
    // This time, however, we needn't remove items from the vector or add them
    // back in. The k variable helps us move through the vector without modifying
    // its contents.
    int thisWeight = treasures[k].weight;
    int thisValue = treasures[k].value;
    int result;

    if (thisWeight <= capacity)
    {
        // Take it. Adding the current item to our knapsack adds to our running value
        // but also reduces the capacity of our knapsack.
        int with = thisValue + knapsack(treasures, capacity - thisWeight, k + 1);

        // Don't take it. Leaving this item behind in hopes of finding other, better
        // items with which to fill our knapsack means we don't gain any value, but
        // we also don't reduce the capacity of our knapsack.
        int without = knapsack(treasures, capacity, k + 1);

        result = max(with, without);
    }
    else
    {
        // Don't take it. This is the branch where the current item is too heavy to take.
        // So, we don't have the luxury of making a binary choice about whether to take
        // the item with us. We must leave it behind.
        result = knapsack(treasures, capacity, k + 1);
    }
    return result;
}

// Wrapper function
int knapsack(Vector<treasureT>& treasures, int capacity)
{
    // We kick off our journey by considering what to do with the element at index 0.
    // Another way to interpret this is that when we kick off our journey, we have so
    // far considered what to do with zero of the items in our vector.
    return knapsack(treasures, capacity, 0);
}
