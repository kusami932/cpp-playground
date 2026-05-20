#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string anystring = "INDIA";
    for (int i = 0; i < anystring.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << anystring[j];
        }
        cout << "\n";
    }
    return 0;
}