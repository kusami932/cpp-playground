#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

typedef struct tagCircularQueue
{
    int Capacity;
    int Front;
    int Rear;
    Node *Nodes;
} CQueue;

void CQ_CreateQueue(CQueue **Queue, int Capacity);
void CQ_DestroyQueue(CQueue *Queue);
void CQ_Enqueue(CQueue *Queue, ElementType Data);;
ElementType CQ_Dequeue(CQueue *Queue);
int CQ_GetSize(CQueue *Queue);
int CQ_IsEmpty(CQueue *Queue);
int CQ_IsFull(CQueue *Queue);

#endif