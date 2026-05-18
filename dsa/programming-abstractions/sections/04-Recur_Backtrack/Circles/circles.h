/*
3. Circle of Life (Circle.h/.cpp)
Topics: Classes

Write a class named Circle that stores information about a circle. 
Your class must implement the following public interface:

class Circle {
	// constructs a new circle with the given radius
	Circle(double r); 
	// returns the area occupied by the circle
	double area() const;
	// returns the distance around the circle 
	double circumference() const;

	// returns the radius as a real number
	double getRadius() const;
	// returns a string representation such as "Circle{radius=2.5}"
	std::string toString() const;
};

You are free to add any private member variables or methods that you think are necessary. 
It might help you to know that there is a global constant PI (which you can use freely 
without needing to define anything extra) storing the approximate value of π, roughly 3.14159.
*/

#pragma once

class Circle
{
public:
    Circle(double radius);

    double area() const;
    double circumference() const;
    double getRadius() const;
    std::string toString() const;

private:
    double r;
}