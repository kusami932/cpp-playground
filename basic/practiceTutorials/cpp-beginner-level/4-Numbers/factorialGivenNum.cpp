#include <iostream>
using namespace std;

int main()
{
    int n;
    unsigned long long factRes = 1;
    cout << "Enter the number: ";
    cin >> n;

    while (n > 0)
    {
        factRes *= n;
        n -= 1;
    }
     cout << "Factorial of " << n << " is " << factRes << endl;
    return 0;
}