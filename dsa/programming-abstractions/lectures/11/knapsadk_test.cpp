#include <iostream>
#include "console.h"
#include "vector.h"
#include "SimpleTest.h"
using namespace std;

/*

0-1 Knapsack (and Some Broken Solutions)
Suppose we have a sack with a weight capacity c, and we have items with weights (wi) and values (vi). 
The goal of the 0-1 knapsack problem is to stuff items into our knapsack in such a way that maximizes 
the total value of the items we take (without exceeding the bag's maximum weight capacity). 
The problem is "0-1" because our decision about each item is binary: we either take it, or we don't. 

Similarity to Subset Generation

The recursive backtracking approach to the 0-1 knapsack problem is similar to the approach we have 
already seen for generating all subsets of a given set: for every element in a set, we made a binary 
choice about whether to include it in the subset we were generating or not, and we made two recursive 
calls accordingly -- one for each of those possibilities. Similarly, with 0-1 knapsack, we make binary 
choices about whether or not to place items from some input vector into our knapsack -- and make two 
recursive calls to explore those two distinct possibilities. A key distinction between the subset and 
knapsack algorithms is that in the knapsack algorithm, when we are faced with an item that is too heavy 
for our knapsack, we are forced to leave it behind -- and, accordingly, we make only one recursive call 
to reflect that. So, with the knapsack problem not every item in our input vector is subject to a binary choice.
*/

struct treasureT 
{
    int weight;
    int value;
};

// Assumes weights and values vectors have equal size.
Vector<treasureT> createTreasureVector(Vector<int>& weights, Vector<int>& values)
{
    Vector<treasureT> treasures;

    for(int i = 0; i < weights.size(); i++)
    {
        treasureT myTreasure;
        myTreasure.weight = weights[i];
        myTresure.value = values[i];
        treasures.add(myTreasure);
    }

    return treasures;
}

PROVIDED_TEST("simple knapsack test")
{
    Vector<int> weights = {4, 2, 3, 1, 6, 4};
    Vector<int> values = {6, 4, 5, 3, 9, 7};

    Vector<treasureT> treasures = createTreasureVector(weights, values);
    int capacity = 10;

    EXPECT_EQUAL(knapsack(treasures, capacity), 19);
    
}

PROVIDED_TEST("another simple knapsack test")
{
    Vector<int> weights = {8, 3, 3, 3, 1};
    Vector<int> values = {160, 58, 58, 58, 2};

    Vector<treasureT> treasures = createTreasureVector(weights, values);
    int capacity = 10;

    EXPECT_EQUAL(knapsack(treasures, capacity), 176);
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}