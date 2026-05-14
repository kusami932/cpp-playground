#include <iostream>
#include "console.h"
using namespace std;

int treasureHunt(int *a, int *b, int *c)
{
    int totalBooty = 0;

    // Print memory addresses contained in a, b, and c. These are like treasure maps
    // that help us navigate the perilous seas of memory to reach our treasure hoards!
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    // If we didn't dereference a, b, and c below, we would just be attempting to add
    // memory addresses to totalBooty rather than going to main() and getting the
    // integer values that a, b, and c are pointing to.
    totalBooty += *a;
    totalBooty += *b;
    totalBooty += *c;

    // If we didn't dereference a, b, and c below, we would just be attempting to set
    // these local pointers to zero rather than going back to main() and setting the
    // various treasureHoard variables to zero.
    *a = 0;
    *b = 0;
    *c = 0;

    return totalBooty;
}

int main()
{
    int treasureHoard1 = 200;
    int treasureHoard2 = 300;
    int treasureHoard3 = 500;

    // Print memory addresses of treasure hoard variables.
    cout << "&treasureHoard1: " << &treasureHoard1 << endl;
    cout << "&treasureHoard2: " << &treasureHoard2 << endl;
    cout << "&treasureHoard3: " << &treasureHoard3 << endl;

    // Notice that we need the ampersands (&) below because our function is using
    // three pointer parameters.
    cout << treasureHunt(&treasureHoard1, &treasureHoard2, &treasureHoard3) << endl << endl; // 1000

    cout << "treasureHoard1: " << treasureHoard1 << endl; // treasureHoard1: 0
    cout << "treasureHoard2: " << treasureHoard2 << endl; // treasureHoard2: 0
    cout << "treasureHoard3: " << treasureHoard3 << endl; // treasureHoard3: 0

    return 0;
}
/*
memory diagram (while in the treasureHunt() function, before wiping out the three hoards)

treasureHunt():

  totalBooty (0x7fd0223e0c04)
  +----------------+
  |       0        |
  +----------------+

  a                   0x7fd0223e0bf8
  +--------------------------------+
  |          0x7fd0223e0c2c        |
  +--------------------------------+

  b                   0x7fd0223e0bf0
  +--------------------------------+
  |          0x7fd0223e0c30        |
  +--------------------------------+

  c                   0x7fd0223e0be8
  +--------------------------------+
  |          0x7fd0223e0c34        |
  +--------------------------------+


main():

  treasureHoard1 (0x7fd0223e0c2c)
  +----------------+
  |      200       |
  +----------------+

  treasureHoard2 (0x7fd0223e0c30)
  +----------------+
  |      300       |
  +----------------+

  treasureHoard3 (0x7fd0223e0c34)
  +----------------+
  |      500       |
  +----------------+

*/