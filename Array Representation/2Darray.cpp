#include <iostream>
using namespace std;
int main()
{
    // 1St Method :: The whole array is created in the stack
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};

    // 2Nd Method :: The half array is created in the stack and the other half is created in the heap
    int *B[3]; // Here we have created the rows in the stack
    B[0]=new int[4]; // Here we are assigning each row with the column
    B[1]=new int[4];
    B[2]=new int[4];
    
    // 3Rd Method :: The whole array is created in the heap
    int **C;
    C=new int*[3]; // Here we are creating the rows in the heap
    C[0]=new int[4]; // here we are creating the columns in the heap
    C[1]=new int[4];
    C[2]=new int[4];
   
    C[1][2]=25;
    cout <<C[1][2]<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout <<A[i][j]<<endl;
            cout <<B[i][j]<<endl;
            cout <<C[i][j]<<endl;
        }
    }
    
    return 0;
}
