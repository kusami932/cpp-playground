#ifndef CIRCULAR_LINKEDLIST_H
#define CIRCULAR_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode *PrevNode;
    struct tagNode *NextNode;
} Node;


Node *CLL_CreateNode(ElementType NewData);
void CLL_DestroyNode(Node *Node);
void CLL_AppendNode(Node **Head, Node *NewNode);
void CLL_InsertAfter(Node *Current, Node *NewNode);
void CLL_RemoveNode(Node **Head, Node *Remove);
Node *CLL_GetNodeAt(Node *Head, int Location);
int CLL_GetNodeCount(Node *Head);

#endif

