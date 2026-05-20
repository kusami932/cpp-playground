// 2. Program to add two integers and print output

#include <iostream>
using namespace std;

int main()
{
    int num1, num2, sum = 0;

    cout << "\n##=== Program to add two integer numbers==##\n\n";
    
    cout << "Enter first integer number: ";
    cin >> num1;
    cout << "Enter second integer number: ";
    cin >> num2;

    sum = num1 + num2;
    cout << "\n" << num1 << " + " << num2 << " = " << sum << endl;
    
    return 0;
    
}
