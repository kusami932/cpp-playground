#include <iostream>
using namespace std;

int main()
{
    long long num;
    cout << "Enter the number the check Armstrong: ";
    cin >> num;

    long long reverse;
    long long multiFact = 1;
    for (long long i = num; i > 0; i /= 10)
    {
        reverse = reverse * 10 + (i % 10);
        multiFact *= 10;
    }

    if (reverse == num)
        cout << num << " is Armstrong number." << endl;
    else
        cout << num << " is Not a Armstrong number." << endl;
    return 0;
}