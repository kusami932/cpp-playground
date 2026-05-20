/*

Aggregation, single level inheritance (public/private/protected), multilevel public inheritance

This C++ program defines two classes: 'Tyre' and 'Car'. The 'Tyre' class represents a car tire 
and contains private attributes for width, aspect ratio, and diameter. It has constructors to 
initialize the tire attributes and getters to access them. The 'Tyre' class also includes a 
'PrintTyre' function to display the tire's width, aspect ratio, and diameter.

The 'Car' class represents a car and contains private attributes for model (year) and 
company (manufacturer). It also has an attribute for a 'Tyre' object, which is a composition 
to represent the car's tires. The 'Car' class includes a constructor that takes the model, 
company name, and a 'Tyre' object as arguments to initialize the car attributes. The 'Car' class 
also includes a 'PrintCar' function to display the car's model, company, and tire information.

In the 'main' function, the program demonstrates the usage of these classes. It creates a 
'Tyre' object named 'tNew' with width 12, aspect ratio 10, and diameter 13, and then displays 
its information using 'PrintTyre'. Next, it creates a 'Car' object named 'cNew' with model year 
2016, company name "Honda", and the 'tNew' tire object. Finally, it displays the car's information 
using 'PrintCar', which also includes the details of the tire using the 'PrintTyre' function.

Aggregation: 
The  aggregation  relationship  is  used  to  represent  the  ownership  or  a  whole/part 
relationship between classes. The aggregate object has one or more parts which may be 
shared with other objects of the same class or other classes. The objects that make up the 
parts are created and destroyed independently of the aggregate object.

*/

#include <iostream>
using namespace std;

class Tyre {
    private:
        int* width;
        int* aspect_ratio;
        int* diameter;

    public:
        Tyre();
        Tyre(int, int, int);
        ~Tyre();
        int getWidth();
        int getAspect_Ratio();
        int getDiameter();

    void PrintTyre() {
        cout << "WIDTH : " << *width << "     ASPECT_RATIO : " 
        << *aspect_ratio << "     DIAMETER : " << *diameter;
    }
};

Tyre::Tyre() {
    width = 0;
    aspect_ratio = 0;
    diameter = 0;
}

Tyre::Tyre(int W, int A, int D) {
    this->width = new int;
    this->aspect_ratio = new int;
    this->diameter = new int;

    *width = W;
    *aspect_ratio = A;
    *diameter = D;

}

int Tyre::getWidth(){
		return *width;
	}

int Tyre::getAspect_Ratio(){
		return *aspect_ratio;
	}

int Tyre::getDiameter(){
		return *diameter;
	}
Tyre::~Tyre(){
        delete width,aspect_ratio,diameter;
	}

class Car {
    private:
        int* model;
        string* company;
        Tyre* t1;

    public:
        Car(int M, string C, Tyre& T){
            this->model = new int;
            this->company = new string;
            *model = M;
            *company = C;
            t1 = new Tyre(T.getWidth(), T.getAspect_Ratio(), T.getDiameter());
        }
        ~Car() {
            delete model, company, t1;
        }
    void PrintCar() {
    cout << "MODEL : "<< *model <<"     COMPANY : "<< *company <<"     ";
}
};

int main() {
    Tyre tNew(12, 10, 13);
    tNew.PrintTyre();
    endl(cout);
    Car cNew(2016, "Honda", tNew);
    cNew.PrintCar();
    return 0;
}