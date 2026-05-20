⁡⁣⁢⁣/*
Problem 3: Dynamic Character Array

Write C++ program which creates a dynamic character array.
    Ask the user to enter a string in that array.
    Ask user to enter a substring and search either that substring is present in character array or not.
    If the substring is not present ask user to enter the input again unless user enters the substring present in an array.

Example
    Input:
        Please enter string: My name is abc
    Output:
        Please enter substring: xyz
            Sorry entered substring is not present in array.
        Please enter substring: abc
            The entered substring is present in array.
*/⁡

/*
Task Description
This C++ program allows the user to input two strings and checks 
if the second string (substring) is present within the first string.

  1. Two character pointers 'c1' and 'c2' are declared, and dynamic memory is allocated for both to store the strings.
  2. Two integer variables 'len1' and 'len2' are declared to store the lengths of the first and second strings, respectively.

  3. The program enters a 'do-while' loop to continuously prompt the user to input the two strings.
    3.1 The first string is stored in 'c1', and its length is calculated using 'strlen'.
    3.2 The second string is stored in 'c2', and its length is calculated using 'strlen'.

  4. The program then checks if the second string 'c2' is a substring of the first string 'c1' using 'strstr' function.
    4.1 If 'c2' is found as a substring within 'c1', it displays a message indicating that the substring is present.
    4.2 If 'c2' is not found as a substring within 'c1', it displays a message indicating that the substring is not present.

  5. The loop continues until the substring 'c2' is found in the first string 'c1'.

  6. After finding the substring, the dynamically allocated memory for 'c1' and 'c2' is released using 'delete[]'
    to prevent memory leaks.

  Note: The program showcases the usage of dynamic memory allocation for character arrays and the 'strstr' function
  from the 'cstring' library to find substrings. The 'do-while' loop ensures that the user continues to enter
  strings until a substring match is found.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char* c1 = new char[100];
    char* c2 = new char[100];
    int len1, len2;

    do {
        cout << "Enter first string: ";
        cin.ignore();
        cin.getline(c1, 100);
        len1 = strlen(c1);

        cout << "Enter second string: ";
        cin.getline(c2, 100);
        len2 = strlen(c2);

        if(strstr(c1, c2)) cout << "The entered substring is present in the array!!" << endl;
        else cout << "Sorry, the entered substring is not present in the array!!" << endl;
    } while (!strstr(c1, c2))

    // Clean up the dynamically allocated memory
    delete[] c1;
    delete[] c2;

    return 0;
}