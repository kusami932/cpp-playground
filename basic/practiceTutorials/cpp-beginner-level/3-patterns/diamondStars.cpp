#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int rows, numOfSpace, numOfStars = 1;
    cout << "Enter the no. of rows in the pattern : ";
    cin >> rows;

    for (int i = 1; i <= (rows * 2); i++)
    {
        numOfSpace = abs(rows - i);

        for (int j = 1; j <= numOfSpace; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= numOfStars; j++)
        {
            cout << "*";
        }
        
        if (i >= rows)
            numOfStars = numOfStars - 2;
        else
            numOfStars = numOfStars + 2;
        cout << endl;
    } 
    return 0;
}