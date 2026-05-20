⁡⁣⁢⁣/*
Problem 2: shallow / deep copy, copy constructor, passing objects as parameters to functions

Implement a class called BiggerInt. The BiggerInt class will have two data members:
    • int* big_int_; // Pointer to the int array that holds the big integer
    • int int_length_; // Variable to store the length of the big integer 

While an integer is of 4 bytes in size with a range of -2,147,483,648 to 2,147,483,647. 
A big integer can store long integer numbers with no size limitation.

1. Write a default constructor and initialize big_int_ to nullptr = BiggerInt();

2. Write an overloaded constructor and perform deep copy = BiggerInt (const int * obj, int size);

3. Write a copy constructor and perform deep copy. Print “Copy Constructor Called” and 
observe the scenarios where the copy constructor is called = BiggerInt (const BiggerInt & obj);

------ Member functions ------

4. Write a member function to make a deep copy of the big_int_ of the passed 
BiggerInt obj into the big_int_ of the object which called this function.
• void assign(const BiggerInt & obj);

5. Write a member function which will overload the above assign function and performs 
the same operations but the argument passed to this function is a pointer integer array.
• void assign(const int * big_int, int size);

6. Write a member function to append the big_int_ of the passed BiggerInt obj to the 
end of big_int_ of the object which called this function.
• void append(const BiggerInt & obj);

7. Write a member function which will overload the above append function and performs 
the same operations but the argument passed to this function is a pointer integer array.
• void append(const int* big_int, int size);

8. Write a member function to compare the big_int_ of BiggerInt obj with the big_int_ of 
the object which called this function. Return 0 for equal, 1 for less than and 2 for greater than.
• int compareTo(const BiggerInt & obj);

9. Write a member function which overloads the above compareTo function and performs 
the same operations but the argument passed to this function is a pointer integer array.
• int compareTo(const int* big_int, int size);

10. Write a member function to display the big_int_ on screen. 
If big_int_ is empty, print “No Value Assigned”.
• void display();

11. Write a destructor to deallocate any dynamically allocated memory.
• ~ BiggerInt();

12. Write a suitable main() function to test all the functions of the BiggerInt class.

Note:
• Deallocate all dynamically allocated memory.
• Do not use any string class built-in functions except for strlen(), if required.
• Follow all the code indentation, naming conventions and code commenting guidelines.
*/⁡

/*
Task Description
This C++ program defines a class 'BiggerInt' to work with arrays of integers 
representing large integers.The class provides various member functions to perform 
operations like assignment, appending, comparison, and display.

  The 'BiggerInt' class has the following private data members:
  - 'big_int_': A pointer to an integer to store the dynamic array of integers representing a large integer.
  - 'int_length_': An integer to store the number of elements in the 'big_int_' array.

  The class has the following public member functions:

  - 'BiggerInt()': Default constructor to initialize 'big_int_' to NULL and 'int_length_' to 0.
  - 'BiggerInt(const int* obj, int size)': Constructor to create a 'BiggerInt' object and initialize it with the given array of integers and its size.
  - 'BiggerInt(const BiggerInt& obj)': Copy constructor to create a deep copy of a 'BiggerInt' object.

  - 'void assign(const BiggerInt& obj)': Function to assign the 'big_int_' array from another 'BiggerInt' object.
  - 'void assign(const int* big_int, int size)': Function to assign the 'big_int_' array from a given array of integers and its size.
  - 'void append(const BiggerInt& obj)': Function to append the 'big_int_' array from another 'BiggerInt' object to the current object's 'big_int_'.
  - 'void append(const int* big_int, int size)': Function to append a given array of integers and its size to the current object's 'big_int_'.
  - 'int compareTo(const BiggerInt& obj)': Function to compare the 'int_length_' of the current object and another 'BiggerInt' object.
    Returns 2 if the current object has a smaller 'int_length_', 0 if both have the same 'int_length_', and 1 if the current object has a larger 'int_length_'.
  - 'int compareTo(const int* big_int, int size)': Function to compare the 'int_length_' of the current object and a given array of integers and its size.
    Returns 2 if the current object has a smaller 'int_length_', 0 if both have the same 'int_length_', and 1 if the current object has a larger 'int_length_'.
  - 'void display()': Function to display the elements of the 'big_int_' array in a space-separated format.
    If the 'big_int_' array is empty, it prints "No value assigned."

  The 'BiggerInt' class also has a destructor 'BiggerInt::~BiggerInt()' to deallocate the dynamically allocated 'big_int_' array.

  In the 'main' function:
  - Two integer arrays 'arr' and 'arr2' are defined to hold sample large integers.
  - Two 'BiggerInt' objects 'pro' and 'pro1' are created using different constructors and initialized with the sample arrays.
  - The 'display' function is called to show the elements of 'pro' and 'pro1'.
  - The 'append' function is called to append the 'big_int_' array of 'pro1' to the 'big_int_' array of 'pro'.
  - The 'display' function is called again to show the updated elements of 'pro'.

  Note: The program demonstrates the use of a custom class 'BiggerInt' to work with large integers represented as arrays of integers.
  It showcases various member functions that handle assignment, appending, and comparison of large integers.
*/

#include <iostream>
using namespace std;

class BiggerInt {
    private:
        int* big_int_;
        int int_length_;

    public:
        BiggerInt();
        BiggerInt(const int* obj, int size);
        BiggerInt(const BiggerInt &obj);

        void assign(const BiggerInt &obj);
        void assign(const int *big_int, int size);

        void append(const BiggerInt &obj);
        void append(const int *big_int, int size);

        int compareTo(const BiggerInt &obj);
        int compareTo(const int* big_int, int size);

        void display();
        
        ~BiggerInt();
};

BiggerInt::BiggerInt() {
    big_int_ = 0;
    int_length_ = 0;
}

BiggerInt::BiggerInt(const int* obj, int size) {
    int_length_ = size;
    big_int_ = new int[int_length_];
    for(int i = 0; i < int_length_; i++) {
        big_int_[i] = obj[i];
    }
}

BiggerInt::BiggerInt(const BiggerInt &obj){
    int_length_ = obj.int_length_;
    big_int_ = new int[obj.int_length_];
    for (int i = 0; i < int_length_; i++) {
        big_int_[i] = obj.big_int_[i];
    }
}

BiggerInt::assign(const BiggerInt &obj) {
    int_length_ = obj.int_length_;
    big_int_=new int[obj.int_length_];
    for(int i=0;i<int_length_;i++){
		big_int_[i]=obj.big_int_[i];
	}
}

BiggerInt::assign(const int * big_int, int size) {
    int_length_ = size;
    big_int_ = new int[int_length_];
    for(int i=0;i<int_length_;i++){
		big_int_[i]=big_int[i];
	}
}

void BiggerInt::append(const BiggerInt &obj) {
    int new_size = int_length_ + obj.int_length_;
    int* dummy = new int[new_size];

    for (int i = 0, k = 0; i < new_size; i++) {
        if (i < int_length_) {
            dummy[i] = big_int_[i];
        } else {
            dummy[i] = obj.big_int_[k++];
        }
    }
    big_int_ = dummy;
    int_length_ = new_size;
}

void BiggerInt::append(const int* big_int, int size) {
    int new_size = int_length_ + size;
    int* newArray = new int[new_size];

    for (int i = 0, k = 0; i < new_size; i++) {
        if (i < int_length_) {
            newArray[i] = big_int_[i];
        } else {
            newArray[i] = big_int[k++];
        }
    }

    big_int_ = newArray;
    int_length_ = new_size;
}

int BiggerInt::compareTo(const BiggerInt &obj) {
    if(obj.int_length_ > int_length_) return 2; 
    else if (obj.int_length_==int_length_) return 0;
    else return 1;
}

int BiggerInt::compareTo(const int* big_int, int size) {
    if (size > int_length_) return 2;
    else if (size == int_length_) return 0;
    else return 1;
}

void BiggerInt::display() {
    if (int_length_ == 0) cout << "No value assigned" << endl;
    else {
        for(int i = 0;i < int_length_; i++){
	        	cout << big_int_[i] << " ";
		    }
		    cout << endl;
    } 
}

BiggerInt::~BiggerInt() {
    delete[] big_int_;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[6] = {6, 7, 8, 9, 10, 11};

    BiggerInt pro(arr, 5);
    BiggerInt pro1(arr2, 6);

    pro.display();
    pro1.display();
    pro.append(pro1);
    pro.display();

    return 0;
}