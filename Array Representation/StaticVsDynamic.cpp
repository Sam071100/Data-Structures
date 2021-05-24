#include <iostream>
using namespace std;
int main()
{
    int A[5]={2,4,6,8,10};// This array will be created in the stack
    int *p;

    p=new int[5];// This array will be created in the heap
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;

    // Here as we have not initialized the value for the p[4] so it will take Garbage Value and not the value 0 as the dynamic array took.
    for (int i = 0; i < 5; i++)
    {
        cout <<A[i]<<endl;
        cout <<p[i]<<endl;
    }
    
    return 0;
}
