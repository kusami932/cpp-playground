⁡⁣⁢⁣/*
Problem 2: Setters & Getters, Constructor

A phone number, such as (212) 767-8900, can be thought of as having three parts: 
The Area code (212), the exchange (767), and the number (8900). Write a program 
that uses a CLASS to store these three parts of a phone number separately. Call 
the class Phone. Create two class variables of type phone. Initialize one, and 
have the user Input a number for the other one. Then display both numbers. 

Example

    INPUT:
        Enter your area code, exchange, and number: 415 555 1212
    OUTPUT:
        My number is (212) 767-8900
        Your number is (415) 555-1212
*/⁡

/*
Task Description
This C++ program defines a 'Phone' class to store and display phone numbers. The class has 
private data members 'areaCode', 'exchange', and 'number' to represent the phone number components.

  1. The default constructor is provided to initialize the phone number components to 0.
  2. The 'Input' function allows the user to input the area code, exchange, and number.
  3. The 'Display' function displays the phone number in the format (areaCode) exchange-number.

  Note: The program demonstrates the use of a class to represent phone numbers and the member 
  functions to interact with class data. The 'Phone' class encapsulates the phone number 
  details and provides methods to input and display phone numbers.
*/

#include <iostream>
using namespace std;

class Phone {
    private:
        int areaCode, exchange, number;
    
    public:
        Phone() : areaCode(0), exchange(0), number(0) {}

        void Input() {
            cout << "Enter your area code, exchange, and number: ";
            cin >> areaCode >> exchange >> number;
        }

        void Display() {
            cout << "My number is (" << areaCode << ") " << exchange << "-" << number << endl;
        }
};

int main() {
    Phone myNumber;
    Phone yourNumber;

    myNumber.Display();

    yourNumber.Input();

    cout << "Your number is: " << endl;
    yourNumber.Display();

    return 0;
}