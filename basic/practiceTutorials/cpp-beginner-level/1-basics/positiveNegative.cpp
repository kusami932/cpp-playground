// check if the number is positive or negative

#include <iostream>
using namespace std;

int main(){
    int num;

    cout << "\nEnter a number: ";
    cin >> num;

    if (num > 0)
        cout << "\nNumber is positive." << endl;
    
    else if (num < 0)
        cout << "\nNumber is negative." << endl;

    else
        cout << "\nNumber is equal to zero." << endl;
    return 0;
}
