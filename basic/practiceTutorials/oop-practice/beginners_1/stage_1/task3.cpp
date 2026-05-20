⁡⁣⁢⁣/*
Problem 3: 1-D Dynamic Array (Part 1)
Write a C++ program that declares and initializes an array dynamically and finds 
the index of the first occurrence of the second largest element in the array.
*/⁡

/*
Task Description
  This C++ program allows the user to input the size of an array and then takes input for the array elements.
  It then finds and displays the index of the second largest value in the array.

  1. Prompt the user to enter the limit (size) of the array.
  2. Create a dynamically allocated integer array 'arr' of size 'limit' to store the elements.
  3. Prompt the user to input 'limit' number of integer values, which are stored in the array 'arr'.
  4. Initialize variables 'largest' and 'secondmax' to keep track of the index of the largest and second largest values in the array.
  5. Iterate through the array elements and find the index of the largest value, storing it in 'largest'.
  6. While finding the largest value, also update 'secondmax' to keep track of the index of the second largest value.
  7. Display the index of the second largest value found in the array.

  Note: The program uses dynamic memory allocation to create an array with a size specified by the user. By iterating
  through the array, it identifies the index of the second largest value without sorting the array explicitly.
*/

#include <iostream>
using namespace std;

int main()
{
    int limit;

    cout << "Enter limit of the array = ";
	cin >> limit;
    
    int *arr = new int [limit]; // dynamically allocating int array 
    cout << "Enter values upto " << limit << endl;
	
	for (int i = 0; i < limit; i++)
    {
		cin >> arr[i];
	}

    int largest = 0, secondmax = 0;

    for (int i = 0; i < limit; i++)
    {
        if (arr[i] > arr[largest])
        {
            secondmax = largest;
            largest = i;
        }
    }
    cout << endl;
	cout << "Index of the 2nd largest value is = " << secondmax << endl;
	
	return 0;

}