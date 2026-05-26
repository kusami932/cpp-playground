#include "LinkedListStack.h"

void LLS_CreateStack(LLStack **Stack)
{
    (*Stack) = (LLStack*)malloc(sizeof(LLStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

void LLS_DestroyStack(LLStack *Stack)
{
    while (!LLS_IsEmpty(Stack))
    {
        Node *Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }

    free(Stack);
}

Node *LLS_CreateNode(char *NewData)
{
    Node *NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);

    strcpy( NewNode->Data, NewData);

    NewNode->NextNode = NULL;

    return NewNode;
}

void LLS_DestroyNode(Node *_Node)
{
    free(_Node->Data);
    free(_Node);
}

void LLS_Push(LLStack *Stack, Node *NewNode)
{
    if (Stack->List == NULL)
        Stack->List = NewNode;

    else
        Stack->Top->NextNode = NewNode;

    Stack->Top = NewNode;
}

Node *LLS_Pop(LLStack *Stack)
{
    Node *TopNode = Stack->Top;

    if (Stack->List == Stack->Top)
    {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else
    {
        Node *CurrentTop = Stack->List;
        while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
        {
            CurrentTop = CurrentTop->NextNode;
        }

        Stack->Top = CurrentTop;
        Stack->Top->NextNode = NULL;
    }

    return TopNode;
}

Node *LLS_Top(LLStack *Stack)
{
    return Stack->Top;
}

int LLS_GetSize(LLStack *Stack)
{
    int Count = 0;
    Node *Current = Stack->List;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    
    return Count;
}

int LLS_IsEmpty(LLStack *Stack)
{
    return (Stack->List == NULL);
}