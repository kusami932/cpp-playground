// Objective: Use the C++ compiler and make to build a program.
#include <cstdlib>

int main() {
    exit(0);
}

/*
Q: What would this program do?

A: It exits without printing anything. The 0 argument to exit means that the program exits “normally”; exit statuses 
other than 0 are typically used for errors. 

Skimming reference material to extract the information you need is an important programming skill that we hope you’ll learn through practice.

Note that in C++, #include <cstdlib> provides access to the C standard library. In C, this would be written 
#include <stdlib.h>, but #include <cstdlib> is more idiomatic in C++.
*/