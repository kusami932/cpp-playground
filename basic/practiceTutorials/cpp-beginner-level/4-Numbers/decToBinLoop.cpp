#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the decimal number to get binary: ";
    cin >> num;

    int binary = 0, multiNum = 1;

    for (int i = num; i > 0; i /= 2)
    {
        binary = ((i % 2) * multiNum) + binary;
        multiNum *= 10;
    }

    cout << "Binary equivalent = " << binary << endl;
    return 0;
}