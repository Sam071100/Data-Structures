#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    cout <<"Enter the size of the stack\n";
    cin >>st->size;
    st->top=-1;
    st->s=new int[st->size];
}

void Display(struct stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        cout <<st.s[i]<<endl;
    }
}

void push(struct stack *st, int x)
{
    if (st->top==st->size-1)
    {
        cout <<"Stack Overflow\n";
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct stack *st)
{
    int x=-1;
    if (st->top==-1)
    {
        cout <<"Stack Underflow\n";
    }
    else
    {
        x=st->s[st->top--];
    }
    return x;
}

int peek(struct stack st, int pos)
{
    int x=-1;
    if (st.top-pos+1<0)
    {
        cout <<"Invalid Index\n";
    }
    else
    {
        x=st.s[st.top-pos+1];
    }
    return x;
}

int stackTop(struct stack st)
{
    if (!isEmpty(st))
    {
        return st.s[st.top];
    }
    else
    {
        return -1;
    } 
}

int isEmpty(struct stack st)
{
    if (st.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack st)
{
    if (st.top==st.size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack st;
    create(&st);

    push(&st, 10);  
    push(&st, 20);  
    push(&st, 30);  
    push(&st, 40);  
    push(&st, 50);  
    // push(&st, 60);  cannot push if the size of the stack is 5
    Display(st);
    cout <<"The element at the position 4 is "<<peek(st,4)<<endl;
    cout <<"After popping\n";
    cout <<"The popped value is "<<pop(&st)<<endl;
    cout <<"The popped value is "<<pop(&st)<<endl;
    cout <<"The popped value is "<<pop(&st)<<endl;
    cout <<"The popped value is "<<pop(&st)<<endl;
    cout <<"The popped value is "<<pop(&st)<<endl;
    cout <<"The popped value is "<<pop(&st)<<endl;
    cout <<"is the stack empty "<<isEmpty(st)<<endl;
    Display(st);
    return 0;
}
