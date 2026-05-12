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

/*
b. Average value
Write a function named avgNeighborhood that takes a grid and a grid location and returns the average of 
all the values in the neighborhood of the grid location. A neighborhood is defined as all cells in a grid 
that border the grid location in all four directions(N, S, E, W). If the average is not an integer, 
return a truncated average.
*/

// solution1 (we put the 4 locations in a Vector and loop over them)
int avgNeighborhood(Grid<int>& grid, GridLocation loc)
{
    Vector<GridLocation> possibleLocations = {
        {loc.row - 1, loc.col}, // North
        {loc.row + 1, loc.col}, // south
        {loc.row, loc.col + 1}, // east
        {loc.row, loc.col - 1}  // west
    };

    int sum = 0;
    int numValidLocations = 0;
    for (GridLocation dir : possibleLocations)
    {
        if(grid.inBounds(dir))
        {
            sum += grid[dir];
            numValidLocations += 1;
        }
    }
    return sum / numValidLocations;
}

// solution2 (Don't do this please!! We manually get all 4 locations and sum them up)
int avgNeighborhood(Grid<int>& grid, GridLocation loc) {
    int sum = 0;
    int numValidLocations = 0;

    GridLocation north {loc.row - 1, loc.col};
    if (grid.inBounds(north)) {
        sum += grid[north];
        numValidLocations += 1;
    }

    GridLocation south {loc.row + 1, loc.col};
    if (grid.inBounds(south)) {
        sum += grid[south];
        numValidLocations += 1;
    }

    GridLocation east {loc.row, loc.col + 1};
    if (grid.inBounds(east)) {
        sum += grid[east];
        numValidLocations += 1;
    }

    GridLocation west {loc.row, loc.col - 1};
    if (grid.inBounds(west)) {
        sum += grid[west];
        numValidLocations += 1;
    }

    return sum / numValidLocations;
}
