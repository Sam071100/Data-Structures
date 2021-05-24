#pragma once
#ifndef QueueCpp_h
#define QueueCpp_h
#include <iostream>
using namespace std;

class Node // Node of a tree
{
    public:
      Node *lchild;
      int data;
      Node *rchild;
};

class Queue
{
    int front;
    int rear;
    int size;
    Node **Q; // [Node*]*: Pointer to [Pointer to Node]
    public:
      Queue()
      {
          front = rear =-1;
          size = 10;
          Q = (Node** )new int[size];
      }

      Queue(int size)
      {
          front = rear = -1;
          this->size = size;
          Q = (Node**) new int[this->size];
      }

      void enqueue(Node *x);
      Node* dequeue();
      int isEmpty();
};

void Queue::enqueue(Node *x)
{
    if ((rear+1)%size==front)
    {
        cout <<"Queue is Full\n";
    }
    else
    {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

Node* Queue::dequeue() // returns a Node pointer
{
    Node *x = NULL;
    if (front==rear)
    {
        cout <<"Queue is Empty\n";
    }
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

int Queue::isEmpty()
{
    return front==rear; // If equal returns 1 else returns false
}
#endif