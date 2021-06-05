#include <iostream>
#include "chains.h"
using namespace std;

int Hash(int key)
{
    return key%10;
}

void Insert(struct Node **H, int key)
{
    int index = Hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10]; // Hash table

    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
    
    Insert(HT, 12);
    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    struct Node *temp = Search(HT[Hash(22)], 22);
    cout <<temp->data;
    return 0;
}
