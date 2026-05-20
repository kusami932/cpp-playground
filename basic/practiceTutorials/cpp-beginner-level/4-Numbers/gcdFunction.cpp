/*
Pseudo Code of the Algorithm-
Step 1:  Let  a, b  be the two numbers
Step 2:  a mod b = R
Step 3:  Let  a = b  and  b = R
Step 4:  Repeat Steps 2 and 3 until  a mod b  is greater than 0
Step 5:  GCD = b
Step 6: Finish
*/

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a & b);
}

int main()
{
    int a = 105, b = 30;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}