// 3. Find the ASCII value of a character

#include <iostream>
using namespace std;

int main(){
    
    char c;
    int ASCII;

    cout << "\nEnter the character: ";
    
    cin >> c;
    ASCII = (int)c;
    cout << "\n" << ASCII;

    return 0;

}