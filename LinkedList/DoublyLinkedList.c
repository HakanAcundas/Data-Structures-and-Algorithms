#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next, *prev;
};

struct Node* head;

struct Node* GetNewNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int value)
{
    struct Node* newNode = GetNewNode(value);
    if (head != NULL)
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        head = newNode;
    }
}

int Size()
{
    int size = 0;
    struct Node* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    return size;
}

void Print()
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    struct Node* temp = head;
    // Go to last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    // Traverse back
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    InsertAtHead(5);
    InsertAtHead(10);
    InsertAtHead(1);

    printf("Print(): ");
    Print();

    printf("ReversePrint(): ");
    ReversePrint();

    printf("Size(): %d", Size());

    return 0;
}