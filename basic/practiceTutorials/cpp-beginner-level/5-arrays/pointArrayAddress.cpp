#include<iostream>

using namespace std;

int main()
{
  int size;
  cout << "Enter the size of the array:";
  cin >> size;

  int arr[size];

  for(int i = 0; i < size; i++)
    cout <<" Address of " << i << "th elements is :" << &arr[i] << "\n";

  return 0;
}