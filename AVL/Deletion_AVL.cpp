#include <iostream>
using namespace std;

class Node
{
    public:
     Node *lchild;
     int data;
     Node *rchild;
     int height;
};

class AVL
{
    public:
     Node *root;
     AVL()
     {
         root = NULL;
     }
     //Methods for inserting and deleting
     int NodeHeight(Node *p);
     int BalanceFactor(Node *p);
     Node* LLRotation(Node *p);
     Node* RRRotation(Node *p);
     Node* LRRotation(Node *p);
     Node* RLRotation(Node *p);
     Node* InPre(Node *p);
     Node* InSucc(Node *p);

     Node* Rinsert(Node *p, int key);

     void Inorder(Node *p);
     void Inorder()
     {
         Inorder(root);
     }
     Node* getRoot()
     {
         return root;
     }

     Node* Delete(Node *p, int key);
};

int AVL::NodeHeight(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl+1 : hr+1;
}

int AVL::BalanceFactor(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

Node* AVL::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    // Height of plr will not change
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl); // This node's height is being computed because we have added the plr lchild as p rchild

    if (root == p)
    {
        root =pl;
    }
    return pl;
}

Node* AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}

Node* AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild =plr ->lchild;
    p->lchild = plr ->rchild;
    plr->rchild=p;
    plr->lchild=pl;

    // taking Height changes into consideration
    plr->height=NodeHeight(plr);
    pl->height =NodeHeight(pl);
    p->height=NodeHeight(p);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}

Node* AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    // Modifying height changes
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    if (root == p)
    {
        root = prl;
    }
    return prl;
}

// Left Sub tree mai right most child in the leaf node
Node* AVL::InPre(Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

// Right Sub tree mai left most child in the leaf node
Node* AVL::InSucc(Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

Node* AVL::Rinsert(Node *p, int key)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild=t->rchild=NULL;
        t->height = 1; // Starting height from 1 onwards instead of 0
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
    

    // Updating the height while returning
    p->height = NodeHeight(p);

    // Balance factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->rchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }
    
    return p;
}

void AVL::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout <<p->data<<" ";
        Inorder(p->rchild);
    }
}

Node* AVL::Delete(Node *p, int key)
{
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
        delete p;
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        Node *q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // Updating the height
    p->height = NodeHeight(p);

    // Balance factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) // L1 Rotation
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) // L-1 Rotation
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) // R-1 Rotation
    {
        return RLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) // R1 Rotation
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0) // L0 Rotation
    {
        return LLRotation(p);
    }else if (BalanceFactor(p) == 2 && BalanceFactor(p->rchild) == 0) // R0 Rotation
    {
        return RRRotation(p);
    }

    return p;
}

int main()
{
    AVL tree;

    int A[] = {10,20,30,25,28,27,5};
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        tree.root = tree.Rinsert(tree.root, A[i]);
    }
    
    tree. Inorder();
    cout <<endl;

    tree.Delete(tree.root, 28);

    tree.Inorder();
    cout <<endl;
    return 0;
}
