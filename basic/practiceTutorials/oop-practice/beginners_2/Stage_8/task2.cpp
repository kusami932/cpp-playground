/*
This C++ program defines three classes: 'Point', 'Circle', and 'Cylinder'.
The 'Point' class represents a point in 2D space with x and y coordinates.
It has constructors to initialize the coordinates and getters to access them.

The 'Circle' class represents a circle in 2D space and is defined using its center point (an instance of the 'Point' class) 
and radius. The class contains functions to get the radius and center coordinates of the circle, as well as 
a function to check if a given point lies on the circle.

The 'Cylinder' class represents a cylinder in 3D space. It is defined by its height, two circles (top and bottom) to 
represent the base, and their respective radii. The class includes a constructor to initialize the cylinder and 
functions to get its height. It also has a function to check if a given point lies on the cylinder, either on 
its top and bottom circles or between them along the height.

In the 'main' function, the program demonstrates the usage of these classes.
It creates an instance of the 'Point' class, sets its coordinates, and displays them. It then creates an instance of 
the 'Circle' class, sets its center point and radius, and checks if the previously created point lies on the circle.
Similarly, it creates an instance of the 'Cylinder' class, sets its attributes, and checks if the point lies on the cylinder.
The program then prints the results of these checks.
*/

#include <iostream>
using namespace std;


class Point() {
    private:
        int* x;
        int* y;
    
    public:
        // Constructors, get/set, destructor
        Point(int, int);
        int getX();
        int getY();
        ~Point();
        void display();
        void setX(int);
        void setY(int);

};

Point::Point(int x, int y) {
    this->x = new int;
    this->y = new int;

    *x = x;
    *y = y;
}

int Point::getx() {
    return *x;
}

int Point::gety() {
    return *y;
}

Point::~Point() {
    delete x, y;
}

void Point::display() {
    cout << "(" << *x << "," << *y << ")";
}

float square(int sqr) {
    return sqr * sqr;
}


class Circle {
    private:
        float* radius;
        Point* coordinate;
        Point Pin;
    
    public:
        Circle(float, int, int);
        float getRadius();
        int getCenterX();
        int getCenterY();
        ~Circle();
        bool checkOnCircle(Point& p1); // Returns true if point lies in circle, false otherwise
};

float Circle::getradius() {
    return *radius;
}

int Circle::getCenterX() {
    return coordinate->getX();
}

int Circle::getCenterY() {
    return coordinate->getY();
}

Circle::~Circle() {
    delete radius;
}

bool Circle::checkOnCircle(Point& p1) {
    float length = square(p1.getX() - coordinate->getX()) - square(p1.getY() - coordinate->getY());
    if (length <= square(*radius))
        return true;
    else
        return false;
}

class Cylinder {
    private:
        int height;
        Circle* top;
        Circle* bottom;

    public:
        Cylinder(int, float, int, int, float, int, int);
        int getHeight();
        ~Cylinder();
        bool checkOnCylinder(Point& p1);
};

Cylinder::Cylinder(int h, float rad1, int x1, int y1, float rad2, int x2, int y2)
    : top(new Circle(rad1, x1, y1)), bottom(new Circle(rad2, x2, y2)) {
        height = h;
    }

int Cylinder::getHeight() {
    return height;
}

Cylinder::~Cylinder() {
    delete top;
    delete bottom;
}

bool Cylinder::checkOnCylinder(Point& p1) {
    bool isOnTop = top->checkOnCircle(p1);
    bool isOnBottom = bottom->checkOnCircle(p1);

    if (isOnTop && isOnBottom) return true;

    // Check if point lies between the top and bottom circles along the height of the cylinder
    int centerY = (top->getCenterY() + bottom->getCenterY()) / 2;
    int heightHalf = height / 2;
    int pointY = p1.getY();

    return (pointY >= centerY - heightHalf && pointY <= centerY + heightHalf);
}

int main() {
    cout << "x and y coordinate : ";
    Point a(3, 4);
    a.display();
    cout << endl;

    cout << "Check on circle : ";
    Circle c(5.3, 2, 3);
    cout << c.checkOnCircle(a) << endl;

    cout << "Check on cylinder : ";
    Cylinder cl(7, 5.3, 2, 9, 5.3, 2, 3);
    cout << cl.CheckOnCylinder(a) << endl;

    return 0;
}