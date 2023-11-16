#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 16

struct Stack
{
    int* elements;
    int top;
    int limitExceedCounter;
};

struct Stack* GetNewStack()
{
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
    *newStack = (struct Stack){ .top = -1, .limitExceedCounter = 1, .elements = malloc(sizeof(int) * MAX_SIZE)};

    return newStack;
}

void Push(struct Stack* stack, int value)
{
    if (stack->top == (MAX_SIZE * stack->limitExceedCounter) - 1)
    {
        printf("Info: Limit exceeded, preparing new array.\n");
        stack->limitExceedCounter *= 2;
        int* newElements = stack->elements;
        stack->elements = malloc(sizeof(int) * MAX_SIZE * stack->limitExceedCounter);
        for (int i = 0; i <= stack->top; i++)
        {
            stack->elements[i] = newElements[i];
        }
        free(newElements);
        stack->top++;
        stack->elements[stack->top] = value;
    }
    else
    {
        int a = stack->top;
        stack->top++;
        stack->elements[stack->top] = value;
    }
}

void Pop(struct Stack* stack)
{
    if (stack->top == -1)
    {
        printf("Error: Empty Stack\n");
    }
    else
    {       
        stack->top--;
    }
}

int Top(struct Stack* stack)
{
    return stack->elements[stack->top];
}

bool IsEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void Print(struct Stack* stack)
{
    if (stack->top == -1)
    {
        printf("Error: Empty Stack\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++)
    {
        printf(" | %d | ", stack->elements[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack* myStack = GetNewStack();
    printf("IsEmpty() %d\n", IsEmpty(myStack));
    Push(myStack, 2);
    Push(myStack, 1);
    Push(myStack, 11);
    Push(myStack, 11);
    Push(myStack, 22);
    Push(myStack, 33);
    printf("IsEmpty() %d\n", IsEmpty(myStack));

    printf("\nCurrent Top value is: %d \n", Top(myStack));
    Pop(myStack);
    printf("Current Top value is: %d \n", Top(myStack));

    Print(myStack);

    struct Stack* myStack2 = GetNewStack();
    printf("IsEmpty() %d\n", IsEmpty(myStack2));
    Push(myStack2, -22);
    Push(myStack2, -1);
    Push(myStack2, -33);

    Print(myStack2);
    Pop(myStack2);
    Print(myStack2);
    

    return 0;
}
