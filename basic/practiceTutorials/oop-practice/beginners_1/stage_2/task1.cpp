⁡⁣⁢⁣/*
Problem 1: 1-D Dynamic Arrays (Part 3)

a) Write a function int* InputArray(int& size) that asks user to enter size of required 
array, allocates the memory on heap, takes input in array and returns its pointer.

b) Write a function void OutputArray(const int* myArray, const int& size) that takes a 
pointer to an integer array and prints its data. Write main function to test above functionality.
Why is the parameter size passed as const? Write your answer in comments

c) Write a function int* CompressArray(int* oiginalArr, int& size) that 
takes a sorted array and removes duplicate elements from this array.

Sample Run:
    Input:
        Enter Size of array: 10
        Enter 10 elements: 1 2 2 2 3 3 3 3 3 7
    Output
        Array after Compression: 1 2 3 7

Your function will compress the original array, allocate new array of compressed size 
(compressed size is 4 in above example) on heap, copy updated array in new array and 
return the new array. Take input from user by calling int* InputArray(int& size) 
(function you implemented in Task 1 part a). Call CompressArray, call 
OutputArray(function you implemented in Task 1 part b) to display the final output.
*/⁡

/*
Task Description
This C++ program demonstrates the dynamic input, compression, and output of an integer array.

  1.The function 'InputArray' takes a reference to an integer 'size' and dynamically 
    allocates memory for an integer array. It prompts the user to input the size and 
    elements of the array and returns a pointer to the dynamically created array.

  2.The function 'OutputArray' takes a constant integer pointer 'myarray' and a 
    constant integer reference 'size'. It displays the elements of the array 
    pointed to by 'myarray' using pointer arithmetic.

  3.The function 'CompressArray' takes an integer pointer 'originalArr' and a 
    reference to an integer 'size'. It creates a new dynamically allocated integer 
    array 'compressedArr' to store the compressed version of the original array.
    The function compresses the original array by removing duplicate consecutive elements.
    It then updates the 'size' parameter with the new compressed size, 
    deallocates the memory of the original array, and returns the compressed array.

  4.In the 'main' function, the user is prompted to input the length of 
    the array. It calls the 'InputArray' function to dynamically create 
    the array and fill it with user-provided values. It then displays the 
    original array using the 'OutputArray' function.

  5.The 'CompressArray' function is called to obtain the compressed version of the original array.
    The compressed array is then displayed using the 'OutputArray' function.

  6.Finally, memory allocated for the compressed array is deallocated using 'delete[]' to prevent memory leaks.

  Note: The program showcases dynamic memory allocation and manipulation of arrays using pointers.
  Remember to free up the memory allocated using 'new' with 'delete[]' to prevent memory leaks.
*/

#include <iostream>
using namespace std;

int* InputArray(int& size) {
    cout << "Enter the size of array: ";
    cin >> size;

    int* array = new int[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    return array;
}

void OutPutArray(const int* myarray, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << *(myarray + i) << " ";
    }
}

int* CompressArray(int* originalArr, int& size) {
    int* compressedArr = new int[size];
    int compressedSize = 0;

    compressedArr[compressedSize++] = originalArr[0];
    for (int i = 1; i < size; i++) {
        if (originalArr[i] != originalArr[i - 1]) {
            compressedArr[compressedSize++] = originalArr[i];
        }
    }
    size = compressedSize;

    delete[] originalArr;
    return compressedArr;
}

int main() {

    int length;
    cout << "Enter length of the array: ";
    cin >> length;

    int* array = InputArray[length];

    cout << "The values are: ";
    OutputArray(array, length);
    cout << endl;

    int compressedSize = length;
    int* compressedArray = CompressArray(array, compressedSize);

    cout << "Array after Compression: ";
    OutputArray(compressedArray, compressedSize);
    cout << endl;

    // Don't forget to deallocate the memory
    delete[] compressedArray;
    return 0;

}