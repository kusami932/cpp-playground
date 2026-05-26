#include "CircularQueue.h"

void CQ_CreateQueue(CQueue **Queue, int Capacity)
{
    (*Queue) = (CQueue*)malloc(sizeof(CQueue));
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;

}

void CQ_DestroyQueue(CQueue *Queue)
{
    free(Queue->Nodes);
    free(Queue);
}

void CQ_Enqueue(CQueue *Queue, ElementType Data)
{
    int Position = 0;

    if (Queue->Rear == Queue->Capacity)
    {
        Position = Queue->Rear;
        Queue->Rear = 0;
    }
    else
    {
        Position = Queue->Rear++;
    }

    Queue->Nodes[Position].Data = Data;
}

ElementType CQ_Dequeue(CQueue *Queue)
{
    int Position = Queue->Front;

    if (Queue->Front == Queue->Capacity)
        Queue->Front = 0;
    
    else Queue->Front++;

    return Queue->Nodes[Position].Data;
}

int CQ_GetSize(CQueue *Queue)
{
    if (Queue->Front <= Queue->Rear)
        return Queue->Rear - Queue->Front;
    else 
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

int CQ_IsEmpty(CQueue *Queue)
{
    return (Queue->Front == Queue->Rear);
}

int CQ_IsFull(CQueue *Queue)
{
    if (Queue->Front < Queue->Rear)
        return (Queue->Rear - Queue->Front) == Queue->Capacity;
    else
        return (Queue->Rear + 1) == Queue->Front;

}