#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};
struct Node* head;

void Insert(int x)
{
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
   temp->data = x;
   temp->next = head;
   head = temp;
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

int Size()
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
   Insert(5);
   Insert(1);
   Insert(-2);
   Insert(111);
   Insert(100);
   Print();
   printf("Size of LinkedList is: %d", Size());

   return 0;
}
