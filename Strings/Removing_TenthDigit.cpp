#include <bits/stdc++.h>
using namespace std;
int main()
{
    int number,index=0, ind=0;
    cin >>number;
    int temp_var=number;
    int array1[100], array2[100];
     while(temp_var!=0){
          array1[index]=temp_var%10;
          index++;
          if(index==1){ // This condition removes the tenth digit number.
          temp_var/=10;
          }
          temp_var/=10;
        }
           if(index>=1){
              for(int i=index-1;i>=0;i--){
                  array2[ind]=abs(array1[i]);
                  ind++;
              }
           }
           cout <<"-";
           for(int i=0;i<ind;i++){
              cout<<array2[i];
           }
    return 0;
}
