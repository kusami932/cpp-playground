/*
6. Count Escape Routes (escape.cpp)
Topics: Recursive counting

Given an input maze and a start GridLocation, write a recursive function that counts the number of ways we can escape the maze. 
In this maze, we can only take one unit steps in two directions: south and east. Just like the maze in assignment 2, the only exit 
out of the maze is at the bottom right corner.
*/

int countWaysToEscape(Grid<bool>& maze, GridLocation location)
{
    // if we are out of bounds or this location is blocked, stop searching
    if(!maze.inBounds(location) || !maze[location])
    {
        return 0;
    }

    // if we are the end of the maze, we've found one way to escape
    if(location == GridLocation{maze.numRows() - 1, maze.numCols() - 1})
    {
        return 1;
    }

    int waysSouth = countWaysToEscape(maze, {location.row + 1, location.col});
    int waysEast = countWaysToEscape(maze, {location.row, location.col + 1});

    return waysSouth + waysEast;
}