#include <iostream>
#include "Queue.cpp"
using namespace std;

struct Node *root = NULL; // Global Variable

void Create()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    cout << "Enter the value of the Root\n";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter the Left Child " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        cout << "Enter the Right Child " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preOrder(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(struct Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

void postOrder(struct Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{
    Create();
    preOrder(root);
    cout <<endl;
    postOrder(root);
    return 0;
}
