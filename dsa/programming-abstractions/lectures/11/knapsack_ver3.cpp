/*
Here is a third solution, which is a twist on our first solution from today: it makes both recursive calls 
("with" and "without") rather than gating the "with" call behind a conditional statement that checks whether 
we could pick up the item in question. 

Solution #1, with its conditional check on the weight of the item in question, is an example of "arm's length recursion," 
which is where we use a conditional statement to actively avoid making a recursive call in a certain situation rather than 
just making that call and allowing a base case to handle it for us. 

Our modified solution needs to rely on the "with" call to detect whether 
we have picked up something that is too heavy for the knapsack.
*/

// Returns the maximum value we can derive by taking treasures from the given vector
// (without the total weight of the treasures we take exceeding the given capacity).
// This version assumes all item weights are positive.
int knapsack(Vector<treasureT>& treasures, int capacity, int valueSoFar)
{
    // If capacity is less than zero, we've tried to pick up something that is too
    // heavy to go into our knapsack, and we have therefore entered into an invalid
    // state. Thus, we derive no value from this state -- not even the valueSoFar.
    if (capacity < 0)
    {
        return 0;
    }

    // No more treasures to choose from means no more value to gain. Similarly,
    // no knapsack capacity means nothing else to gain, assuming all item weights
    // are positive. We return the valueSoFar, since there's nothing else to add.
    // Finito!
    if(treasures.size() == 0 || capacity == 0)
    {
        return valueSoFar;
    }

    treasureT thisOne = treasures[treasures.size() - 1];
    treasures.remove(treasures.size() - 1);

    // Take it. Adding the current item to our knapsack adds to our running value
    // but also reduces the capacity of our knapsack.
    int with = knapsack(treasures, capacity - thisOne.weight, valueSoFar + thisOne.value);

    // Don't take it. Leaving this item behind in hopes of finding other, better
    // items with which to fill our knapsack means we don't gain any value, but
    // we also don't reduce the capacity of our knapsack.
    int without = knapsack(treasures, capacity, valueSoFar);

    // Unchoose. See notes above this function about why we must add this back.
    treasures.add(thisOne);
    return max(with, without);
}

int knapsack(Vector<treasureT>& treasures, int capacity)
{
    // At the start of our journey, we haven't picked up any treasures yet, so our
    // valueSoFar (the third parameter below) is 0 (zero).
    return knapsack(treasures, capacity, 0);
}