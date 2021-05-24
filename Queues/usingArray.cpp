#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int [q->size];
}
void enqueue(struct Queue *q, int x)
{
    if (q->rear==q->size-1)// Full condition of the queue
    {
        cout <<"Queue is Full\n";
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if (q->front==q->rear)// Empty condition of the queue
    {
        cout <<"Queue is Empty\n";
    }
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct Queue q)
{
    for (int i = q.front+1; i <= q.rear; i++)
    {
        cout <<q.Q[i]<<" ";
    }
    cout <<endl;
}
int main()
{
    struct Queue q;
    create(&q,5);// Craeting the Queue

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(q);

    cout <<"Jo phele aya wo phele gaya according to FIFO\n";
    dequeue(&q);
    display(q);
    return 0;
}
