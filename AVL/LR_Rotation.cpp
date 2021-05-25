#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild?p->lchild->height:0;
    hr = p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild?p->lchild->height:0;
    hr = p && p->rchild?p->rchild->height:0;

    return hl-hr;

}

struct Node* LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

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

struct Node* LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

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

struct Node* RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

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

struct Node* RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

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

struct Node* Rinsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        // Height of the tree is starting from 1 not from 0
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild=t->rchild=NULL;
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
    p->height = NodeHeight(p);
    // Peform Rotations:
    if (BalanceFactor(p) ==2 && BalanceFactor(p->lchild)==1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) ==2 && BalanceFactor(p->lchild)==-1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) ==-2 && BalanceFactor(p->lchild)==-1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) ==2 && BalanceFactor(p->lchild)==1)
    {
        return RLRotation(p);
    }
    return p;
}

int main()
{
    root = Rinsert(root , 10);
    Rinsert(root,5);
    Rinsert(root,2);
    return 0;
}
