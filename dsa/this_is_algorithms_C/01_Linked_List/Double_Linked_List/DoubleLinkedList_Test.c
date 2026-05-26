#include "DoubleLinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;

    for (i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nInserting 3000 after [2]...\n\n");

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(Current, NewNode);

    Count = DLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            DLL_AppendNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }

    return 0;

}