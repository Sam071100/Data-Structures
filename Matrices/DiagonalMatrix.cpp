#include <iostream>
using namespace std;

struct Matrix
{
    int *A= new int[10];
    int n;// order of the square matrix.
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i==j)
    {
        m->A[i-1]=x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i==j)
    {
        return m.A[i-1];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i==j)
            {
                cout <<m.A[i]<<" ";
            }
            else
            {
                cout <<"0 ";
            }
        }
        cout <<"\n";
    }
}

int main()
{
    struct Matrix m;
    m.n=4;
    Set(&m, 1,1,5);// Setting the 1st diagonal element as 5 in the 1st row and the 1st Column.
    Set(&m, 2,2,8);// Setting the 2nd diagonal element as 8 in the 2nd row and the 2nd Column.
    Set(&m, 3,3,9);
    Set(&m, 4,4,12);

    cout <<Get(m,2,2)<<endl;

    Display(m);
    return 0;
}
