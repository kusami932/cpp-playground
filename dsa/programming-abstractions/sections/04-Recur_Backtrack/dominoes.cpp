/*
1. Domino Tiling (dominoes.cpp)
Topic: Recursive backtracking

Imagine you have a 2 × n grid that you’d like to cover using 2 × 1 dominoes. The dominoes need to be 
completely contained within the grid (so they can’t hang over the sides), can’t overlap, and have to 
be at 90° angles (so you can’t have diagonal or tilted tiles). There’s exactly one way to tile a 
2 × 1 grid this way, exactly two ways to tile a 2 × 2 grid this way, and exactly three ways to tile 
a 2 × 3 grid this way (can you see what they are?) Write a recursive function

                                int numWaysToTile(int n)

that, given a number n, returns the number of ways you can tile a 2 × n grid with 2 × 1 dominoes.
*/

/*
SOLUTION

If you draw out a couple of sample tilings, you might notice that every tiling either starts with 
a single vertical domino or with two horizontal dominoes. That means that the number of ways to 
tile a 2 × n (for n ≥ 2) is given by the number of ways to tile a 2 × (n – 1) grid (because any 
of them can be extended into a 2 × n grid by adding a vertical domino) plus the number of ways to 
tile a 2 × (n – 2) grid (because any of them can be extended into a 2 × n grid by adding two horizontal 
dominoes). From there the question is how to compute this. You could do this with regular recursion, like this:
*/
int numWaysToTile(int n)
{
    if (n == 0) return 1; // There's one way to tile a 2 x 0 grid: put down no dominoes.
    if (n == 1) return 1; // There's one way to tile a 2 x 1 grid: put down a vertical domino.

    return numWaysToTile(n - 1) + numWaysToTile(n - 2);
}