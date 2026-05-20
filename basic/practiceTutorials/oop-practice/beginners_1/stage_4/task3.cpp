⁡⁣⁢⁣/*
Problem 3: More on Classes

1. Create a class Date having following private data members: Int Day Int Month Int Year
2. [Default Constructor] Write a default Constructor of Date that initializes the object to 1st January 1926 
   and prints “Default Constructor Called” in start. Now run your program and test what does date1 prints?
3. [Print Function] Implement a function Print in Date class which prints a date in following format: dd/mm/yyyy
    Print object date1 in your main function and run the program. How can we initialize the data of date1 at the time of creation?
4. [Input Function] Write a function Input in your Date class that takes input from user to populate a Date object.
    Call “date1.Input()” and “date1.Print()” in your driver program and test it.
5. [Setters] Create an object xmasDay using default constructor. Print xmasDay and see what it prints.
    Write Setters i.e. SetDay, SetMonth and SetYear in your class. Now set xmasDay to 25/12/2020 using Setters in main.
6. [Getters] Write Getters i.e. GetDay, GetMonth and GetYear in your date class. 
    Now print xmasDay using Getters in your Driver program.
*/⁡

/*
Task Description
 This C++ program defines a 'Date' class to represent dates in day/month/year format.
 The class has private data members 'day', 'month', and 'year' to store the date components.

  1. The default constructor initializes the date to 1/1/1926 and displays a message indicating its call.
  2. The 'Print' function displays the date in day/month/year format.
  3. The 'Input' function allows the user to input the day, month, and year.
  4. The 'SetDay', 'SetMonth', and 'SetYear' functions set the day, month, and year, respectively.
  5. The 'GetDay', 'GetMonth', and 'GetYear' functions return the day, month, and year, respectively.

  Note: The program demonstrates the use of a class to represent dates and the member functions to interact with date components.
  It also showcases the constructor and how member functions can be used to set and get the date components.
*/

#include <iostream>
using namespace std;

class Date {

    private:
        int day, month, year;

    public:
        Date() : day(1), month(1), year(1926) {
            cout << "Default Constructor Called" << endl;
        }

        void Print() {
            cout << day << "/" << month << "/" << year << endl;
        }

        void Input() {
            cout << "Enter day, month, and year: ";
            cin >> day >> month >> year;
        }

        void SetDay(int d) { day = d; }
        void SetMonth(int m) { month = m; }
        void SetYear(int y) { year = y; }
        
        int GetDay() { return day; }
        int GetMonth() { return month; }
        int GetYear() { return year; }
};

int main() {
    
    Date date1;
    date1.Print();

    date1.Input();
    date1.Print();

    Date xmasDay;
    xmasDay.Print();

    xmasDay.SetDay(25);
    xmasDay.SetMonth(12);
    xmasDay.SetYear(2020);

    cout << "Updated Christmas Day: ";
    xmasDay.Print();

    return 0;
}