#include <iostream>
#include "arraybasedstack.h"
#include "console.h"
using namespace std;

int main()
{
    ArrayBasedStack s;

    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }

    while(!s.isEmpty())
    {
        cout << s.pop() << endl;
    }

    return 0;
}