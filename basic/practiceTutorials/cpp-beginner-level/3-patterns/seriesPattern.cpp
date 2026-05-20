#include <iostream>

using namespace std;

int main(){
    int end = 40;
    int temp = (1);
    for(int i = 1; i <= 40; i+=3){
        cout << temp * i << " ";
        temp = temp * (-1);
    }

    return 0;
}