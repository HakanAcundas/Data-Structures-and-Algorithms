#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

struct Queue
{
    int front;
    int rear;
    int size;
    int* elements;
};

struct Queue* GetNewQueue()
{
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue*));
    *newQueue = (struct Queue){ .front = -1, .rear = -1, .size = 0, .elements = malloc(sizeof(int) * N)};

    return newQueue;
}

bool IsEmpty(struct Queue* queue)
{
    if (queue->front == -1 && queue->rear == -1)
        return true;
    else
        return false;
}

bool IsFull(struct Queue* queue)
{
    if (queue->size == N)
        return true;
    else
        return false;
}

void Push(struct Queue* queue, int value)
{
    if ((queue->rear + 1) % N == queue->front)
        return;
    else if (IsEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0; 
    }
    else
        queue->rear = (queue->rear + 1) % N;
    queue->elements[queue->rear] = value;
    queue->size++;
}

void Pop(struct Queue* queue)
{
    if (IsEmpty(queue))
    {
        return;
    }
    else if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % N;
    }
}

int Front(struct Queue* queue)
{
    return queue->elements[queue->front];
}

void Print(struct Queue* queue)
{
    for (int i = queue->front; i <= queue->rear; i++)
        printf(" | %d", queue->elements[i]);

    printf("\n");
}

int main()
{
    struct Queue* myQueue = GetNewQueue();
    Push(myQueue, 5);
    Push(myQueue, 2);
    Push(myQueue, 7);
    Print(myQueue);

    Pop(myQueue);
    printf("Front value is: %d\n", Front(myQueue));

    Print(myQueue);

    printf("IsFull: %d", IsFull(myQueue));
    return 0;
}