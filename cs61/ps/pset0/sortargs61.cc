// Objective: Handle C strings, program arguments, and more complex library functions. 
// Implement algorithms described in pseudocode (such as insertion sort).

//  First, use a minimal subset of the C library: use strcmp and an O(n^2) algorithm such as insertion sort or selection sort.
#include <cstring>
#include <cstdio>

// version 1: selection sort
int main1(int argc, char* argv[]) {
    while (argc > 1) {
        // find the smallest argument
        int smallest = 1;
        for (int i = 2; i < argc; ++i) {
            if (strcmp(argv[i], argv[smallest]) < 0) {
                smallest = i;
            }
        }

        // print it
        fprintf(stdout, "%s\n", argv[smallest]);

        // remove it from the argument set
        argv[smallest] = argv[argc - 1];
        --argc;
    }
}


// version 2: insertion sort
int main2(int argc, char* argv[]) {
    for (int i = 2; i < argc; ++i) {
        char *x = argv[i];
        int j = i - 1;
        while (j >= 0 && strcmp(argv[j], x) > 0) {
            argv[j + 1] = argv[j];
            --j;
        }
        argv[j + 1] = x;
    }

    for (int i = 1; i < argc; ++i) {
        fprintf(stdout, "%s\n", argv[i]);
    }
}

// Now do it using C++ library features: 
    // std::string (the C++ library type for automatically-managed strings)
    // std::vector (the C++ library type for automatically-managed, dynamically-sized arrays)
    // std::sort (the C++ library’s sort algorithm)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int main3(int argc, char** argv) {
    // create a vector of the arguments as C++ strings
    std::vector<std::string> args;
    for (int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    // sort the vector’s contents
    std::sort(args.begin(), args.end());

    // print the vector’s contents
    for (size_t i = 0; i < args.size(); ++i) {
        std::cout << args[i] << std::endl;
    }
}

/*
Concise solution using advanced C++ features
More concise code can be written by using more advanced features, such as auto and range initialization.
*/

int main4(int argc, char** argv) {
    std::vector<std::string> args(&argv[1], &argv[argc]); // range initialization
    std::sort(args.begin(), args.end());
    for (auto& s : args) { // range-based for loop
        std::cout << s << std::endl;
    }
}

/*
Here are some other things you should be able to do in C++:

    Dynamically allocate and free an object with new and delete.
    Dynamically allocate and free an array of objects with new[] and delete[].
    Define a structure type.
    Use the C library’s string functions correctly, including memory management.
    Write a function that takes three arguments, a size and two void* pointers to objects, and exchanges the values of the two objects (each of which have the given size).
*/

