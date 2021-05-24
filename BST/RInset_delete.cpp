#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL; // Global variable

struct Node* Rinsert(struct Node *p, int key)
{
    struct Node *t;
    // Reached the last node or creating the root node
    if (p == NULL)
    {
        t = new Node;
        t->data =key;
        t->lchild = t->rchild = NULL;
        return t;
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
int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node* InPre(struct Node *p)
{
    while (p && p->rchild !=NULL)
    {
        p = p->rchild;
    }
    return p;
}

struct Node* InSucc(struct Node *p)
{
    // getting the rightmost node of the left sub tree
    while (p && p->lchild !=NULL)
    {
        p = p->lchild;
    }
    return p;
}

struct Node* Delete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    // Phele jo node ko delete karana hai use search karna hoga
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else // Key is found
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
           q = InPre(p->lchild); // getting the rightmost element in the left sub tree
           p->data = q->data;
           p->lchild= Delete(p->lchild, q->data);
        }
        else if (Height(p->lchild) < Height(p->rchild))
        {
           q = InSucc(p->rchild); // getiing the leftmost element in the right sub tree
           p->data = q->data;
           p->rchild= Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    struct Node *temp;

    root = Rinsert(root, 50);
    Rinsert(root, 10);
    Rinsert(root, 40);
    Rinsert(root, 20);
    Rinsert(root, 30);
    
    RInorder(root);
    cout << endl;

    Delete(root,50);
    RInorder(root);
    cout <<endl;

    Delete(root,10);
    RInorder(root);
    cout <<endl;

    temp = Rsearch(root,10);
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
