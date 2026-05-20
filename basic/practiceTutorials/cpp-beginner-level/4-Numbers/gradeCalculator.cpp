#include <iostream>
using namespace std;

char grade(int score)
{
    if (score > 100 || score < 0)
        return 'I';
    
    switch (score / 10)
    {
        case 1:
            return 'A';
        case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        case 5:
            return 'E';
        default:
            return 'F'; 
    }
}

int main()
{
    int score;
    cout << "Enter the score: ";
    cin >> score;

    char _grade_ = grade(score);

    if (_grade_ == 'I')
        cout << "You have entered invalid score." << endl;
    else 
        cout << "Grade: " << _grade_ << endl;  
  return 0;
    
}