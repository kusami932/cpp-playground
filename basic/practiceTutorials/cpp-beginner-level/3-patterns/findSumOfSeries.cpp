#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int x, n;
    double sum = 0;

    cout << "Enter the value of x : ";
    cin >> x;
    cout << "\nEnter the value of number of terms n : ";
    cin >> n;

    for (int i = 1; i <= n; i++){
        sum = sum + (double(pow(x, i))) / i;
    }

    cout << "\nSum of the series = " << sum ;
    return 0;
}