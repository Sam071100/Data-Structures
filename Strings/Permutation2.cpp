#include <iostream>
using namespace std;

void Perm(char *p, int l, int h)
{
    if (l==h)
    {
        for (int i = 0; i <= h; i++)
        {
            cout <<p[i];
        }
        cout <<" ";
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(p[l],p[i]);
            Perm(p,l+1,h);
            swap(p[l], p[i]);
        }
    }
    
}

int main()
{
    char s[10];
    cin >>s;
    int h;
    for (int i = 0; s[i]!='\0'; i++)
    {
        h=i;
    }
    
    Perm(s,0,h);
    return 0;
}
