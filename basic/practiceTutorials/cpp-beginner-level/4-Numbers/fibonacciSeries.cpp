#include <iostream>
using namespace std;

void printFibonacci(int n)
{
    int temp, pre = 0, next = 1;

    if (n >= 0)
        cout << pre << " ";
    if (n >= 1)
        cout << next << " ";
    
    while(true)
    {
        temp = next + pre;
        if (temp >= n) break;
        cout << temp << " ";
        pre = next;
        next = temp;
    }
    cout << endl;
}


int main()
{
    int n;
    cout << "Enter the certain number till which you want to generate fibonacci series: ";
    cin >> n;

    printFibonacci(n);
    return 0;
}