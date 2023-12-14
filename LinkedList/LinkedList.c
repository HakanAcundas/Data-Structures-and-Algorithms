#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

// Insertion at the begining O(1)
void InsertAtBegining(struct Node** headPointer, int value)
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

void Insert(struct Node** headPointer, int value, unsigned int position)
{
   struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
   temp1->data = value;
   temp1->next = NULL;
   if (position == 0) 
   {
      InsertAtBegining(headPointer, value);
   }
   else 
   {
      struct Node* temp2 = *headPointer;
      for (int i = 0; i < position - 1; i++)
      {
         temp2 = temp2->next;
      }
      temp1->next = temp2->next;
      temp2->next = temp1;
   }
}

// 1) Update the links
// 2) Delete the the node from memory
void Delete(struct Node** headPointer, unsigned int index)
{
   struct Node* temp1 = *headPointer;
   if (index == 0)
   {
      *headPointer = temp1->next;
      free(temp1);
   }
   else
   {
      for (int i = 0; i < index - 1; i++)
      {
         temp1 = temp1->next;
      }
      temp1->next = temp1->next->next;
   }
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

void Reverse(struct Node** headPointer)
{
   struct Node *current, *prev, *next;
   current = *headPointer;
   prev = NULL;
   while (current != NULL)
   {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }   
   *headPointer = prev;
}

void Print(struct Node* head)
{
   struct Node* temp = head;
   while (temp != NULL)
   {
      printf("%d -> ", temp->data);
      temp = temp->next;
   }
}

void RecursionPrint(struct Node* head)
{
   if (head != NULL)
   {
      printf("%d -> ", head->data);
      RecursionPrint(head->next);
   }
   return;
}

void RecursionReversePrint(struct Node* head)
{
   if (head == NULL)
   {
      return;
   }
   RecursionReversePrint(head->next);
   printf("%d -> ", head->data);
}

int main() {
   struct Node* myHead = NULL;
   InsertAtBegining(&myHead, 5);
   InsertAtBegining(&myHead, 1);
   InsertAtBegining(&myHead, -2);
   InsertAtBegining(&myHead, 111);
   InsertAtBegining(&myHead, 100);
   Insert(&myHead, 77, 0);
   Insert(&myHead, 81, 2);
   Print(myHead);

   Delete(&myHead, 6);
   Delete(&myHead, 2);
   Print(myHead);
   printf("\nSize of LinkedList is: %d", Size(myHead));

   printf("\nAfter Reverse() function: ");
   Reverse(&myHead);
   Print(myHead);

   printf("\nRecursivePrint(): ");
   RecursionPrint(myHead);

   printf("\nReverseRecursivePrint(): ");
   RecursionReversePrint(myHead);

   return 0;
}
