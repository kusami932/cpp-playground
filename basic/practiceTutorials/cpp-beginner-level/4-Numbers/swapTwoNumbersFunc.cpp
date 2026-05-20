#include <iostream>
using namespace std;

void swapTwoNum(int *a, int *b)
{
    (*a) = (*a) + (*b);
    (*b) = (*a) - (*b);
    (*a) = (*a) - (*b);

}

int main()
{
    int num1, num2;
    cout << "Enter the first number (num1): " ;
    cin >> num1;
    cout << "Enter the second number (num2): " ;
    cin >> num2;

    swapTwoNum(&num1, &num2);
    cout << "Your entered numbers have been swaped." << endl;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    return 0;
}