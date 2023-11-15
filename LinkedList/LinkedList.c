#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

void Insert(struct Node** headPointer, int value)
{
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
   temp->data = value;
   temp->next = NULL;

   if (*headPointer != NULL)
   {
      temp->next = *headPointer;
   }
   *headPointer = temp;
}

void Print(struct Node* head)
{
   struct Node* temp = head;
   while (temp != NULL)
   {
      printf("%d -> ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int Size(struct Node* head)
{
   int size = 0;
   struct Node* temp = head;
   while (temp != NULL)
   {
      size++;
      temp = temp->next;
   }
   return size;
}

int main() {
   struct Node* myHead = NULL;
   Insert(&myHead, 5);
   Insert(&myHead, 1);
   Insert(&myHead, -2);
   Insert(&myHead, 111);
   Insert(&myHead, 100);
   Print(myHead);
   printf("Size of LinkedList is: %d", Size(myHead));

   return 0;
}
