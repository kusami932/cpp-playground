int knapsack(Vector<treasureT>& treasures, int capacity, int k)
{
    if (k == treasures.size())
    {
        return 0;
    }

    int thisWeight = treasures[k].weight;
    int thisValue = treasures[k].value;

    if(thisWeight <= capacity)
    {
        return max(thisValue + knapsack(treasures, capacity - thisWeight, k + 1),
                 knapsack(treasures, capacity, k + 1)); 
    }
    else
    {
        return knapsack(treasures, capacity, k + 1);
    }
}

int knapsack(Vector<treasureT>& treasures, int capcity)
{
    return knapsack(treasures, capacity, 0);
}