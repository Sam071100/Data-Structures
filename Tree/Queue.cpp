#include <iostream>
using namespace std;

struct Node // Node of a binary tree
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue // using the circular queue for creating the binary tree with some changes in the syntax of the Queue
{
    int size;
    int front;
    int rear;
    Node **Q;// Double pointer because one pointer is for the dynamic array Q and one pointer is for storing the pointer of Node type.
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node**)new Node[size]; // Important Line:: Array of Pointers
            //    or
    // q->Q=(Node**)malloc(q->size*sizeof(Node));
}

void enqueue(struct Queue *q, Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "Queue is Full\n";
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node* dequeue(struct Queue *q)// Returns pointer of Node type
{
    Node *x = NULL;
    if ((q->front) == q->rear)
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear; // if it is true then it will return true else false
}
