#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    int multiple = 1;
    cout << "Enter the no. of terms n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        sum += multiple;
        multiple *= 2;
    }
    cout << "\nSum of the series: " << sum << endl;
    return 0;
}