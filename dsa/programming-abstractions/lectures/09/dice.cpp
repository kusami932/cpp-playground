void rollDice(string soFar, int n)
    {
    if (n == 0)
    {
        cout << soFar << endl;
        return;
    }

    // NOT GREAT
    rollDice(soFar + "1", n - 1);
    rollDice(soFar + "2", n - 1);
    rollDice(soFar + "3", n - 1);
    rollDice(soFar + "4", n - 1);
    rollDice(soFar + "5", n - 1);
    rollDice(soFar + "6", n - 1);
}

void rollDice(int n)
{
    rollDice("", n);
}


