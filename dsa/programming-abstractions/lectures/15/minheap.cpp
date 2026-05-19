// insertion (enQueue)
void creheap(int *arr2, int key, int input)
{
    arr2[key] = input;
    while (key > 1)
    {
        if (arr2[key] < arr[key / 2])
        {
            swap(arr2[key], arr2[key / 2]);
            key /= 2;
        }
        else break;
    }
}

// deletion (deQueue)
void delheap(int *arr3, int key, int heap_size)
{
    int tmp, nextkey;
    while(heap_size >= key * 2)
    {
        if(key * 2 + 1 > heap_size && arr3[key * 2] < arr3[key])
        {
            swap(arr3[key * 2], arr3[key]);
            key = key * 2;
        }
        else if (key * 2 + 1 > heap_size) break;
        else
        {
            if (arr3[key * 2] < arr3[key * 2 + 1])
            {
                tmp = arr3[key * 2];
                nextkey = key * 2;
            }
        }
    }
}