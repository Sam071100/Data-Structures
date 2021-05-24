#include <iostream>
using namespace std;
int main()
{
    char arr[25];
    int count=0;
    gets(arr);
    
    for (int i = 0; arr[i]!='\0'; i++)
    {
        count++;
    }
    cout <<count;
    return 0;
}
