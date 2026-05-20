#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cout << "how many numbers do you have: ";
    cin >> n;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}