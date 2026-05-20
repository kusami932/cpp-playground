#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the no. of rows in Array:";
    cin >> m;
    cout << "Enter the no. of column in Array:";
    cin >> n;

    int arr[m][n];
    int maxCount = 0;
    int maxEvenRow = 0;
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if(arr[i][j] / 2 == 0)
                count++;
        }

        if (count > maxCount)
            maxEvenRow = i;
        count = 0;
    }
    
    
}