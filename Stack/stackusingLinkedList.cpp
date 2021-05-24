#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t = new Node;
    if (t==NULL)
    {
        cout <<"Stack Overflow\n";
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if (top==NULL)
    {
        cout <<"Stack Overflow\n";
    }
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *p=top;
    while (p!=NULL)
    {
        cout <<p->data<<endl;
        p=p->next;
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    Display();
    cout <<endl;
    cout <<"Deleted Element "<<pop()<<endl;
    cout <<"Deleted Element "<<pop()<<endl;
    cout <<endl;
    Display();
    return 0;
}
