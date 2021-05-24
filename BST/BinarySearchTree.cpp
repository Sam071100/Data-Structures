#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL; // Global variable

void insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < p->data)
        {
            t = t->lchild;
        }
        else if (key > p->data)
        {
            t = t->rchild;
        }

        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

struct Node* Rinsert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data =key;
        t->lchild = t->rchild = NULL;
        p =t;
    }
    if (key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }
    return p;
    
}

void RInorder(struct Node *p)
{
    if (p)
    {
        RInorder(p->lchild);
        cout << p->data << " ";
        RInorder(p->rchild);
    }
}

struct Node* Search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

struct Node* Rsearch(struct Node *t, int key)
{
    if (t==NULL)
    {
        return NULL; // empty BST
    }
    if (key == t->data)
    {
        return t;
    }
    else if (key < t->data)
    {
        return Rsearch(t->lchild, key);
    }
    else
    {
        return Rsearch(t->rchild, key);
    }
}

int main()
{
    struct Node *temp;
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    RInorder(root);
    cout << endl;

    temp = Rsearch(root,2);
    if (temp)
    {
        cout << "Element is found " << temp->data << endl;
    }
    else
    {
        cout << "Element is not found\n";
    }

    return 0;
}
