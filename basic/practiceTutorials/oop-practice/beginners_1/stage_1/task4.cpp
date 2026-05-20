⁡⁣⁢⁣/*
Problem 4: 1-D Dynamic Array (Part 2)
Write a C++ program that creates an array after taking size from user. It then adds 
3 to each element of the array. You have to add to the elements using pointer only. 
Array subscript notation cannot be used. Make sure to clear the memory at the end 
and there should be no memory leak.

Example
Input:
    Please enter size: 10
    Enter 10 elements: 1, 11, 2, 30, 26, 12, 5, 9, 15, 28
Output:
    Resulting Array: 4, 14, 5, 33, 29, 15, 8, 12, 18, 31
*/⁡

/*
Task Description
This C++ program allows the user to input the size of an array and then takes input for the array elements.
  It then adds 3 to each element of the array and displays the updated array.

  1. Prompt the user to enter the limit (size) of the array.
  2. Check if the entered limit is non-positive, and if so, display an error message and terminate the program.
  3. Create a dynamically allocated integer array 'arr' of size 'limit' to store the elements.
  4. Prompt the user to input 'limit' number of integer values, which are stored in the array 'arr'.
  5. Create an integer pointer 'ptr' and set it to point to the first element of the 'arr' array.
  6. Iterate through the array 'arr' using the pointer 'ptr', and for each element, add 3 to its value using the pointer.
  7. Display the updated array 'arr' to show the values after adding 3 to each element.

  Note: The program uses dynamic memory allocation to create an array with a size specified by the user. It then manipulates
  the array elements through a pointer 'ptr', adding 3 to each element directly via pointer manipulation.
*/

#include <iostream>
using namespace std;


int main()
{
    int limit;
    cout << "Enter limit of the array = ";
	cin >> limit;
	
	if(limit <= 0){
		cout << "Enter valid and positve limit !!!";
	}
	
	int *arr = new int [limit];
	cout << "Enter values upto " << limit << endl;
	
	for(int i = 0; i < limit; i++){
		cin >> arr[i];
	}

    int *ptr; 
    ptr = arr; // set it to point to the first element of array

    for (int i = 0; i < limit; i++)
    {
        *ptr += 3; // add 3 to element in array
        ptr++; // move to next element
    }

    cout << endl;
	cout << "The values after adding 3 are = ";
	
		for(int i = 0; i < limit; i++)
		    cout << arr[i]; << " ";
	
	return 0;
}