⁡⁣⁢⁣/*
Problem 1: Pointers (Part 1)
Write a program that asks the user to enter integers as inputs to be stored 
in the variables 'a' and 'b' respectively. There are also two integer pointers 
named ptrA and ptrB. Assign the values of 'a' and 'b' to ptrA and ptrB respectively, 
and display them. After this, update the values of variable a and b through their 
pointers and show the data stored on those memory locations through pointer.
*/⁡

/*
Task description
  1. Declare two integer variables 'a' and 'b'.
  2. Create two integer pointers 'ptrA' and 'ptrB' and assign them the addresses of 'a' and 'b'.
  3. Prompt the user to input two integer values, which are stored in 'a' and 'b'.
  4. Display the values of 'a' and 'b' using the pointers 'ptrA' and 'ptrB' respectively.
  5. Update values of 'a' and 'b' by setting values at memory addresses pointed to by 'ptrA' and 'ptrB'.
  6. Display the updated values of 'a' and 'b' using the pointers 'ptrA' and 'ptrB' respectively.
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    // create integer pointers and assign addresss of int variables
    int *ptrA = &a; 
    int *ptrB = &b;

    cout<< "Enter first number = " << endl;
	cin>>a;
	
	cout<< "Enter second number = " << endl;
	cin>>b;

    // display values by dereferencing pointers
    cout << "The values are: " << *ptrA << " & " << *ptrB << endl;

    // update values by setting values at memory addresses pointed
    *ptrA = 30;
    *ptrB = 40;

    cout<< "Updated values of *ptrA and *ptrB are = " 
    << *ptrA << " & " << *ptrB << endl;
	
	return 0;
}