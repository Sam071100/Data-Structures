#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    int *Q;
    public:
     Queue()
     {
         front=rear=-1;
         size=10;
         Q= new int[size];
     }
     Queue(int size)
     {
         front=rear=-1;
         this->size=size;
         Q=new int[this->size];
     }
     void enqueue(int x);
     int dequeue();
     void display();
};
void Queue::enqueue(int x)
{
    if (rear==size-1)
    {
        cout <<"Queue is full\n";
    }
    else
    {
        rear++;
        Q[rear]=x;
    }
}
int Queue::dequeue()
{
    int x=-1;
    if (front==rear)
    {
        cout <<"Queue is Empty\n";
    }
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}
void Queue::display()
{
    for (int i = front+1; i <= rear; i++)
    {
        cout <<Q[i]<<" ";
    }
    if (front+1>rear)
    {
        cout<<"The Queue is Empty\n";
    }
    
    cout <<endl;
}
int main()
{
    Queue q1(5),q2;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q2.enqueue(60);
    q1.display();
    q2.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    q2.dequeue();
    q2.display();
    return 0;
}
