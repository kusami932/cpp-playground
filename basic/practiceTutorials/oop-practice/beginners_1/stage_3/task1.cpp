⁡⁣⁢⁣/*
Problem 1: Dynamic Memory Allocation & Memory Leaks

A C++ program “Encrypt” that creates a dynamic char array of size defined by the user. 
Then takes input of that array from the user and resize the original array to size equal 
to the number of characters entered by the user. Your function now asks the user to 
enter encryption key that can be any alphabet (a-z, A-Z). Encrypt function adds the 
ASCII of encryption key to each char of your input array to generate encrypted sentence. 
If the shift takes you past the end of the alphabet, just rotate back to the front of the 
alphabet. In the case of a shift factor of 3 the message “wxyz” would map to “zabc” 
i.e. w becomes z, x becomes a, y becomes b and z becomes c.

Note: Array subscript notation cannot be used.

Example
    INPUT: (3)
        Enter Size of array: 100
        Enter the array elements: This is object oriented class
        Enter the encryption key: d
    OUTPUT: (2+10)
        New Size of array: 29
        Encrypted array: Pdeojeojkxfaypjkneajpazjyhwoo
*/⁡

/*
Task Description
This C++ program demonstrates encryption using a Caesar cipher with a user-provided encryption key.

  1. The function 'isValidEncryptionKey' takes a single character 'key' and checks 
    if it is a valid encryption key. The function returns 'true' if the key is an 
    alphabet (a-z or A-Z) and 'false' otherwise.

  2. The function 'Encrypt' takes a character array 'arr', an integer 'size', and 
    a character 'key' as inputs. It encrypts the characters in the 'arr' array using 
    the Caesar cipher technique, shifting each character by the value of the 'key'.
    If the 'key' is a valid alphabet (a-z or A-Z), the characters in the array are 
    modified in place.

  3. In the 'main' function:
    3.1 The user is prompted to enter the size of the character array ('arr') dynamically.
    3.2 The 'arr' array is dynamically allocated based on the user-provided size.
    3.3 The user is prompted to input the elements of the 'arr' array.
    3.4 The 'actualSize' variable is used to store the actual number of characters entered by excluding the null terminator.
    3.5 The user is prompted to input the encryption key ('key').
    3.6 A new character array 'resizedArr' is dynamically allocated with a size of 'actualSize + 1' to hold the modified string.
    3.7 The original 'arr' array is copied into 'resizedArr' character by character, and a null terminator is added.
    3.8 The 'Encrypt' function is called with 'resizedArr', 'actualSize', and 'key' to encrypt the array.
    3.8 The original 'arr' and encrypted 'resizedArr' are displayed.

  4. The program deallocates the dynamic memory allocated for 'arr' and 'resizedArr' 
     using 'delete[]' to avoid memory leaks.

  Note: The program showcases dynamic memory allocation for character arrays, input handling 
  for encryption key, and the implementation of a simple Caesar cipher for encryption.
*/

#include <iostream>
using namespace std;

bool isValidEncryptionKey(char key) {
    return((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'));
}

void Encrypt(char* arr, int size, char key) {
    if (!sValidEncryptionKey(key)) {
        cout << "Invalid encryption key! Please enter a valid alphabet (a-z or A-Z)." << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = (arr[i] + key - 'a') % 26 + 'a';
    }
}

int main() {
    int size;
    cout << "Enter Size of array: ";
    cin >> size;

    char* arr = new char[size];

    cout << "Enter the array elements: ";
    cin.ignore(); // Ignore the newline character left in the input buffer
    cin.getline(arr, size);

    // Get the actual number of characters entered
    int actualSize = cin.gcount() - 1; // Excluding the null terminator

    cout << "Enter the encryption key: ";
    char key;
    cin >> key;

    // Resize the original array to the number of characters entered
    char* resizedArr = new char[actualSize + 1]; // +1 for null terminator
    for (int i = 0; i < actualSize; i++) {
        resizedArr[i] = arr[i];
    }
    resizedArr[actualSize] = '\0'; // Add null terminator

    Encrypt(resizedArr, actualSize, key);

    cout << "Original array: " << arr << endl;
    cout << "Encrypted array: " << resizedArr << endl;

    // Deallocate dynamic memory
    delete[] arr;
    delete[] resizedArr;

    return 0;


}