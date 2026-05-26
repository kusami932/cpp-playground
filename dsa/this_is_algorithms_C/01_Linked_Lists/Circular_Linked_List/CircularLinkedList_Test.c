#include "CircularLinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;

    for (i = 0; i < 5; i++)
    {
        NewNode = CLL_CreateNode(i);
        CLL_AppendNode(&List, NewNode);
    }

    Count = CLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = CLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nInserting 3000 after [2]...\n\n");

    Current = CLL_GetNodeAt(List, 2);
    NewNode = CLL_CreateNode(3000);
    CLL_InsertAfter(Current, NewNode);

    Count = CLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = CLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = CLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            CLL_AppendNode(&List, Current);
            CLL_DestroyNode(Current);
        }
    }

    return 0;

}