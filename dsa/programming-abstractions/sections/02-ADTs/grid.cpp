#include <iostream>
#include "console.h"
#include "grid.h"
using namespace std;

/*
1. Grid Basics (grid.cpp)

a. Maximum of a Row in a Grid
Write a function named maxRow that takes a grid of non-negative integers (numbers from 0 to infinity) 
and an in-bounds grid location and returns the maximum value in the row of that grid location.
*/

// solution 1
int maxRow1(Grid<int>& grid, GridLocation loc)
{
    int max = -1;
    for (int col = 0; col < grid.numCols(); col++)
    {
        if(grid[loc.row][col] > max)
        {
            max = grid[loc.row][col];
        }
    }
    return max;
}

// solution 2
int maxRow2(Grid<int>& grid, GridLocation loc)
{
    int max = -1;
    int endCol = grid.numCols() - 1;
    for (GridLocation cell : GridLocationRange(loc.row, 0, loc.row, endCol))
    {
        if(grid[cell] > max)
        {
            max = grid[cell];
        }
    }
    return max;
}