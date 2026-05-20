#include <iostream>
#include <cmath>
using namespace std;

float standard_Deviation(float elements[], int n)
{
    float mean = 0;
    for (int i = 0; i < n; i++)
    {
        mean += elements[i];
    }
    mean /= n;

    float upperTermSum = 0;
    for (int i = 0; i < n; i++)
    {
        upperTermSum = upperTermSum + pow((elements[i] - mean), 2);
    }
    return sqrt((upperTermSum/n));
}

int main()
{
     int n;
    cout << "How many elements do you have: ";
    cin >> n;

    float elements[n];

    for (int i = 0; i < n; i++)
    {
        cin >> elements[i];
    }

    cout << "Standard deviation of the data given: " << (standard_Deviation(elements, n)) << endl;
    return 0;
}