#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void Push(int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = value;
    temp->next = head;
    head = temp;
}

void Pop()
{
    struct Node* temp;
    if (head == NULL)
    {
        printf("Error: Empty Stack\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void Print()
{
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("Error: Empty Stack\n");
        free(temp);
        return;
    }
    while (temp != NULL)
    {
        printf(" -> %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    free(temp);
}

int main()
{
    Print();
    Push(11);
    Push(22);
    Print();

    Pop();
    Print();
    return 0;
}