#include <iostream>
using namespace std;

double avgOfArray(int *arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size ; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

int main()
{
    int size;
    cout << "Size of array: ";
    cin >> size;
    
    int arr[size];

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Average of Array " << avgOfArray(arr, size) << endl;
    return 0;
}