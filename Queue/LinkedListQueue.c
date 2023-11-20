#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void Push(int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = value;
    temp->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void Pop()
{
    struct Node* temp = head;
    if (head == NULL)
        return;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
        head = head->next;
    free(temp);
}

void Print()
{
    struct Node* temp;
    temp = head;
    while (temp != NULL)
    {
        printf(" -> %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Push(3);
    Push(1);
    Push(-22);

    Print();
    Pop();
    Print();
    
    return 0;
}