#include "Queue.cpp"
#ifndef stack_h
#define stack_h
#include <iostream>
// Stack using Array
struct Stack
{
    int size;
    int top;
    struct Node **S; // As it will store the pointers in the array and is pointer to Node. 
};

void StackCreate(struct Stack *st, int size)
{
    st->size=size;
    st->top=-1;
    st->S= new (Node*);
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top==st->size-1)
    {
        cout <<"Stack Overflow\n";
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top==-1)
    {
        cout <<"Stack Underflow\n";
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmptyStack(struct Stack st)
{
    if (st.top==-1)
    {
        return 1;
    }
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top==st.size-1;
}
#endif