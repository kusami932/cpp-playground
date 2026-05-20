⁡⁣⁢⁣/*
Problem 2: Double Pointers, 2D Arrays, Dangling Pointers

i) Write a function char** AllocateMemory(int& rows, int& cols) that takes size of 
   matrix (rows and columns) from user, allocates memory for the matrix and return its pointer.

ii) Write a function char** InputMatrix(char** matrix, const int rows, const int cols) which takes 
    input the values in matrix from user(console) and return the matrix to main function.

iii) Write a function void DisplayMatrix(char** matrix, const int& rows, const int& cols) 
     that displays the matrix in proper format.

iv) Write a function that does the following:

    1. Creates three dynamic char arrays namely alphabets, numbers, and specialchar. (Define the sizes yourself).

    2. Iterate the 2D array and separate alphabet elements and save them in the alphabets array, 
       separate number elements and save them in numbers array and separate special character 
       elements and save them in the specialchar array.

    3. The function returns the three arrays alphabets, numbers, and specialchar.

Note: The three arrays should not consume any extra space. Resize the arrays accordingly.
*/⁡

/*
Task Description
This C++ program demonstrates matrix manipulation to separate different types of characters 
(alphabets, numbers, and special characters) from the user-provided matrix. 

It uses dynamic memory allocation for 2D character arrays and functions to allocate, input, 
display, and separate characters in the matrix. The 'SeparateCharacters' function counts 
occurrences of alphabets, numbers, and special characters and dynamically allocates 
separate arrays for each type. The program prevents memory leaks by deallocating dynamic memory after use.
*/

#include <iostream>
using namespace std;

char** AllocateMemory(int& rows, int& coln) {
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> coln;

    char** matrix = new char* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[coln];
    }

    return matrix;
}

char** InputMatrix(char** matrix, const int rows, const int coln) {
     cout << "Enter the elements of the matrix:" << endl;
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coln; j++) {
            cin >> matrix[i][j];
        }
     }
     return matrix;
}

void DisplayMatrix(char** matrix, const int& rows, const int& coln) {
    cout << "Sample Matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coln; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void SeparateCharacters(char** matrix, const int rows, const int coln,
                        char*& alphabets, char*& numbers, char*& specialchar) {
        
    // Count the occurrences of each character type
    int alphabetCount = 0, numberCount = 0, specialCount = 0
    for (int i = 0; i < rows; i++) {
        int (int j = 0; j < coln; j++) {
            if (isalpha(matrix[i][j])) alphabetCount++;
            else if (isdigit(matrix[i][j])) numberCount++;
            else specialCount++;
        }
    }

    // Resize the arrays
    alphabets = new char[alphabetCount];
    numbers = new char[numberCount];
    specialchar = new char[specialCount];

    // Separate the characters
    int alphabetIndex = 0, numberIndex = 0, specialIndex = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coln; j++) {
            if(isalpha(matrix[i][j])) alphabets[alphabetIndex++] = matrix[i][j];
            else if(isdigit(matrix[i][j])) numbers[numberIndex++] = matrix[i][j];
            else specialchar[specialIndex++] = matrix[i][j];
        }
    }
}

int main() {
    int rows, coln;
    char** matrix = AllocateMemory(rows, coln);

    InputMatrix(matrix, rows, coln);
    DisplayMatrix(matrix, rows, coln);

    char* alphabets;
    char* numbers;
    char* specialChar;

    SeparateCharacters(matrix, rows, coln, alphabets, numbers, specialChar);

    cout << endl;
    cout << "alphabets = ";
    for (int i = 0; i < rows * coln; i++)
        cout << alphabets[i] << " ";
    
    cout << endl;
    cout << "numbers = ";
    for (int i = 0; i < rows * cols; i++)
        cout << numbers[i] << " ";
    
    cout << endl;
    cout << "special characters = ";
    for (int i = 0; i < rows * cols; i++)
        cout << specialchar[i] << " ";
    
    cout << endl;

     // Deallocate dynamic memory
     for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    
    delete[] matrix;

    delete[] alphabets;
    delete[] numbers;
    delete[] specialchar;

    return 0;
}