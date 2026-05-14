#include <iostream>
#include "console.h"
using namespace std;

int treasureHunt(int& a, int& b, int& c)
{
    int totalBooty = 0;

    totalBooty += a;
    totalBooty += b;
    totalBooty += c;

    a = 0;
    b = 0;
    c = 0;

    return totalBooty;
}

int main()
{
    int treasureHoard1 = 200;
    int treasureHoard2 = 300;
    int treasureHoard3 = 500;

    cout << treasureHunt(treasureHoard1, treasureHoard2, treasureHoard3) << endl << endl; // 1000

    cout << "treasureHoard1: " << treasureHoard1 << endl; // treasureHoard1: 0
    cout << "treasureHoard2: " << treasureHoard2 << endl; // treasureHoard2: 0
    cout << "treasureHoard3: " << treasureHoard3 << endl; // treasureHoard3: 0

    return 0;
}