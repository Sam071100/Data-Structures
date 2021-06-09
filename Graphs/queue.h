#ifndef Queue_h
#define Queue_h
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = new Node;
    if (t == NULL) // Heap is full so queue is full as now heap memory can be assigned anymore
    {
        cout <<"Queue is Full\n";
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL) // Queue is empty
        {
            front =  rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
    {
        cout <<"Queue is Empty\n";
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front==NULL;
}

#endif