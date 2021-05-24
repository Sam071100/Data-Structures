#include <iostream>
using namespace std;

void Perm(char *p, int k)
{
    static int A[10]={0};
    static char R[10];
    if (p[k]=='\0')
    {
        R[k]='\0';
        for (int i = 0; R[i]!='\0'; i++)
        {
            cout <<R[i];
        }
        cout <<" ";
    }
    else
    {
        for (int i = 0; p[i]!='\0'; i++)
        {
            if (A[i]==0)
            {
                R[k]=p[i];
                A[i]=1;
                Perm(p, k+1);
                A[i]=0;
            }
            
        }
        
    }
    
}
int main()
{
    char s[10];
    cin >>s;
    Perm(s,0);
    return 0;
}
