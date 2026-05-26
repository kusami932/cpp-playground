#ifndef LL_STACK_H
#define LL_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
    char *Data;
    struct tagNode *NextNode;
} Node;

typedef struct tagLLStack
{
    Node *List;
    Node *Top;
} LLStack;

void LLS_CreateStack(LLStack **Stack);
void LLS_DestroyStack(LLStack *Stack);

Node *LLS_CreateNode(char *Data);
void LLS_DestroyNode(Node *_Node);

void LLS_Push(LLStack *Stack, Node *NewNode);
Node *LLS_Pop(LLStack *Stack);

Node *LLS_Top(LLStack *Stack);
int LLS_GetSize(LLStack *Stack);
int LLS_IsEmpty(LLStack *Stack);

#endif