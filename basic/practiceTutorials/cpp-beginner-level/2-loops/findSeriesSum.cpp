#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    float sum = 0;
    
    cout << "Enter the value: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + float(1/pow(i, 1));
    }
    cout << "Sum = " << sum;
    return 0;
}

