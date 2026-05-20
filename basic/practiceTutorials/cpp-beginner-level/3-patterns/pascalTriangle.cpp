#include <iostream>
#include <string>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = res * i;
    }
    return res;
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int main()
{
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    for (int i = 0; i < rows; i++)
    {
        for (int k = 1; k <= rows - i; k++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || i == j)
                cout << "1" << " ";
            else
                cout << nCr(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}