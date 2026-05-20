⁡⁣⁢⁣/* Problem 2: Pointers (Part 2)
Write a C++ program that creates memory of 1 variable through an integer pointer. 
Input a number into the created memory and find square, cube and half of the input.
Make sure to clear the memory at the end and there should be no memory leak.

Example Output

Input:
    Please enter the integer: 8
Output:
    Square of numbers is: 64
    Cube of numbers is: 512
    Half of numbers is: 4
*/⁡

/*
Task description
This C++ program demonstrates the use of dynamic memory allocation and pointer operations to evaluate
  the square, cube, and half of a user-provided number.

  1. Declare an integer pointer 'ptr' to hold a memory address for an integer value.
  2. Dynamically allocate memory for an integer using the 'new' operator, and store the address in 'ptr'.
  3. Prompt the user to enter a number, which is stored in the memory location pointed to by 'ptr'.
  4. Display the square of the entered number by multiplying the value at 'ptr' with itself.
  5. Display the cube of the entered number by multiplying the value at 'ptr' with itself twice.
  6. Display half of the entered number by dividing the value at 'ptr' by 2.
  7. Deallocate the memory previously allocated for the integer using the 'delete' operator to avoid memory leaks.

  Note: Dynamic memory allocation using 'new' allows for creating variables at runtime and is useful when the
  size of memory needed is not known at compile time. However, it is crucial to deallocate the memory using 'delete'
  to avoid memory leaks and free up memory for reuse.
*/

#include <iostream>
using namespace std;

int main()
{
    int *ptr;
    ptr = new int; // dynamic memory allocation using new operator
    
    cout << "Enter a number for the evaluation = ";
	cin >> *ptr;

    cout << "Square of a number is = ";
	cout << (*ptr) * (*ptr) << endl;
	
	cout << "Cube of a number is = ";
	cout << (*ptr) * (*ptr) * (*ptr) << endl;
	
	cout << "Half of a number is = ";
	cout << (*ptr) / 2 << endl;
	
	delete ptr;
	
	return 0;


}