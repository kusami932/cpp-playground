/*

Use base class pointers to call derived class objects 
Virtual functions and destructors 
See polymorphism in action 

Specifying a function as [virtual] makes sure that whenever we use a base class pointer 
pointing  to  an  object  of  a  derived  class  to  call  a  function,  
the  definition  of  the  method  declared in the derived class is used.

-----------------------------------------------------------------------------
This C++ program demonstrates the concept of polymorphism using a simple banking system.

There is a base class 'Account' that represents a generic bank account with attributes 
'AN' (Account Number) and 'AB' (Account Balance). It has member functions to get and 
set these attributes, and also virtual functions 'Print', 'Credit', and 'Debit'.

Two derived classes, 'CurrentAccount' and 'SavingAccount', are created from the 'Account' class.
The 'CurrentAccount' class adds attributes 'SC' (Service Charges) and 'MB' (Minimum Balance) 
and overrides the 'Print', 'Credit', and 'Debit' functions. The 'SavingAccount' class adds an 
attribute 'IR' (Interest Rate) and also overrides the 'Print', 'Credit', and 'Debit' functions.

In the 'main' function, an array of pointers to the 'Account' base class is created, and 
three different account objects (one 'SavingAccount', one 'CurrentAccount', and one 'Account') 
are dynamically allocated and assigned to the array elements.

Polymorphism is demonstrated by calling the 'Print', 'Credit', and 'Debit' functions 
on the array elements, which results in calling the appropriate functions based on the object type.
*/

#include <iostream>
using namespace std;

class Account {
    private:
        int AN, AB;

    public:
         int getAN() {
                return AN;
            }

        int getAB() {
                return AB;
            }

        void setAN(int acn) {
                AN = acn;
            }

        void setAB(int acb) {
                AB = acb;
            }

        virtual void Print() {
            cout << "Account Number : " << AN << endl
             << "Account Balance : " << AB << endl;
        }

        virtual void Credit(float) { }
        virtual void Debit(float) { }
        virtual ~Account() { cout << "Account destroyed !!" << endl; }
};

class CurrentAccount:public Account {
    private:
        int SC, MB;

    public:
        CurrentAccount() {
            SC = 100;
            MB = 1000;
        }

        void Print() {
            Account::Print();
            cout << "Services Charges : " << SC << endl
             << "Minimum Balance : " << MB << endl;
        }

        void Credit(float amount) {
            setAB(getAB() + amount)
        }

        void Debit(float amount) {
            if (amount <= getAB()){
                setAB(getAB() - amount);
                if (getAB() < MB){
                    setAB(getAB() - SC);
                }
            }
        }

        ~CurrentAccount() {
            cout << "Current Account destroyed !!" << endl;
        }
};

class SavingsAccount : public Account {
    private:
        int IR;

    public:
        SavingsAccount() { IR = 5; }
        void Print() {
            Account::Print();
            cout << "Interest Rate : " << IR << endl;
        }
        void Credit(float amount) {
            setAB(getAB() + amount);
        }

        void Debit(float amount) {
            if (amount <= getAB()) {
                setAB(getAB() - amount);
            }
        }

        ~SavingAccount() {
            cout << "Saving Account destroyed !!" << endl;
        }
};

int main() {
    Account ** alist = new Account*[3];

    alist[0] = new SavingsAccount;
    alist[1] = new CurrentAccount;
    alist[2] = new Account;

    for (int i = 0; i < 3; i++)
        alist[i]->Print();

    alist[0]->Credit(50);
    alist[2]->Debit(333);

    for (int i = 0; i < 3; i++) {
        delete alist[i];
    }
    delete[] alist;

    return 0;
}