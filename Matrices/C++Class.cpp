#include <iostream>
using namespace std;
// Diagonal Matrix
class matrix
{
   private:
    int n;
    int *A;
    public:
    matrix()
    {
        n=2;
        A= new int[2];
    }
    matrix(int n)
    {
        this->n=n;// assigns the global variable or the member of the class to the local variable.
        A= new int[n];
    }
    ~matrix()
    {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};
void matrix::Set(int i, int j, int x)
{
    if (i==j)
    {
        A[i-1]=x;
    }
    
}
int matrix::Get(int i, int j)
{
    if (i==j)
    {
        return A[i-1];
    }
    return 0;
}
void matrix::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                cout <<A[i]<<" ";
            }
            else
            {
                cout <<"0 ";
            }
        }
        cout <<endl;
    }
    
}
int main()
{
    matrix d(4);
    d.Set(1,1,5);
    d.Set(2,2,10);
    d.Set(3,3,15);
    d.Set(4,4,20);
    d.Display();
    return 0;
}
