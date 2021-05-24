#include <iostream>
using namespace std;
int main()
{
   typedef int*  intpointer; 
   intpointer p,q;
   p=new int[5];
   p[0]=1,p[1]=2,p[2]=3,p[3]=4,p[4]=5;

   for (int i = 0; i < 5; i++)
   {
       cout <<p[i]<<endl;
   }
   cout<<"This is the middle array\n";
   q=new int[10];
   for (int i = 0; i < 5; i++)
   {
       q[i]=p[i];
       cout<<q[i]<<endl;// THhis checks whether all the elements of the p[] got copied into q[].
   }
   delete []p;
   p=q; // Here the pointer p started pointing the new pointer
   q=NULL;
   cout <<"This is the new array\n";
   for (int i = 0; i < 10; i++)
   {
       cout <<p[i]<<endl;
   }
   
    return 0;
}
