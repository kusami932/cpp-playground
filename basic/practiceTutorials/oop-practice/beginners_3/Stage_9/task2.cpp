⁡⁣⁢⁣/*
Inheritance

Write a class LocalPhone that contains an attribute phone to a local telephone number.  
The class contains member functions to input and display phone number. Write a child class 
NatPhone for national phone numbers that inherits LocalPhone class. It additionally contains an 
attribute to store city code. It also contains member functions to input and show the city code.  
Write another class IntPhone for international phone numbers that inherits NatPhone class. 
It additionally contains an attribute to store country code. It also contains member functions to 
input and show the country code.
*/

⁡⁢⁢/*
This C++ program defines three classes: 'LocalPhone', 'natphone', and 'intphone'. The 
'LocalPhone' class represents a local phone number and contains a private attribute 'Phone' 
to store the phone number. It has a constructor to initialize the 'Phone' attribute and 
functions to set and display the phone number.

The 'natphone' class is derived from the 'LocalPhone' class and represents a national phone number.
It adds an additional private attribute 'citycode' to store the city code. The 'natphone' class 
has a constructor that initializes both 'citycode' and the 'Phone' attribute inherited from the 
base class. It also includes functions to set and display the city code.

The 'intphone' class is derived from the 'natphone' class and represents an international 
phone number. It adds an additional private attribute 'countrycode' to store the country code.
The 'intphone' class has a constructor that initializes both 'countrycode' and the 'citycode' 
attribute inherited from the base class. It also includes functions to set and display the country code.

In the 'main' function, the program demonstrates the usage of these classes by creating objects 
of each class. It creates a 'LocalPhone' object 'lp' with phone number "1234567", a 'natphone' 
object 'np' with city code 999 and phone number "1234567", and an 'intphone' object 'ip' with 
country code 42, city code 999, and phone number "1234567".

The program then displays the local phone number using 'showphone', the city code using 'showcity', 
the country code using 'showcountry', and the final result, which shows the country code followed 
by the city code and the phone number, using 'showcountrycode'.
*/

#include <iostream>
using namespace std;

class LocalPhone {
    private:
        string phone;
    
    public:
        LocalPhone(string n) { phone = n; }
        void setPhone(string n) { phone = n; }
        void showPhone() { cout << this->phone; }
};

class NatPhone:public LocalPhone {
    private:
        int cityCode;
    
    public:
        NatPhone(int c, string n):LocalPhone(n) { cityCode = c; }
        void setCityCode(int c) { cityCode = c; }
        void showCityCode() { 
            cout << this->cityCode;
            showPhone();
        }
        void showCity() {
            cout << this->cityCode;
        }
};

class IntPhone:public NatPhone {
    private:
        int countryCode;

    public:
        IntPhone(int country, int c, string n):NatPhone(c, n) {
            countryCode = country;
        }

        void setCountryCode(int c) {
            countryCode = c;
        }

        void showCountryCode(){
            cout << this->countryCode;
            showCityCode();
        }

        void showCountry() {
            cout << this->countryCode;
        }
};

int main() {
    LocalPhone lp("1234567");
    NatPhone np(999, "1234567");
    IntPhone ip(42, 999, "1234567");

    cout << "Local Phone Number : ";
    lp.showPhone();
    endl(cout);

    cout << "City Code : ";
    np.showCity();
    endl(cout);

    cout << "International Code : ";
    ip.showCountry();
    endl(cout);

    cout << "Final result : ";
    ip.showCountryCode();

return 0;


}