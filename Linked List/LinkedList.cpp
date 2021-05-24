#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL; // Global pointer

void Create(int A[], int n)
{
    struct Node *t,*last;

    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while (p!=NULL)
    {
        cout <<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    int A[]={3,5,7,10,15};

    Create(A,5);
    Display(first);

    return 0;
}
