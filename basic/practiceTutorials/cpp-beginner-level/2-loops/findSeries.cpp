#include <iostream>
using namespace std;

int main(){
    int n, sum = 0;
    cout << "Enter the value of n: ";
    cin >> n;
    sum = n * (n + 1) / 2;
    cout << "\nSum = " << sum << endl;
    return 0;
}