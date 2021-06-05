#ifndef Chains_h
#define Chains_h
#include <cstddef> // For including the NULL 
struct Node
{
    int data;
    struct Node *next;
};

// Array of Linked List will be passed
void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q=NULL, *p = *H;

    // *H is the pointer pointing to the first node

     t = new Node;
     t->data =x;
     t->next = NULL;

     if (*H == NULL)
     {
         *H = t;
     }
     else
     {
         while (p && p->data<x)
         {
             q=p;
             p=p->next;
         }
         if (p == *H) // Inserting before the 1st Node
         {
             t->next = *H;
             *H = t;
         }
         else // Agar upar wala while loop chala toh
         {
             t->next = q->next;
             q->next = t;
         }
     }
}

struct Node *Search(struct Node *p, int key)
{
    while (p!=NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
#endif