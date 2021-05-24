#include <iostream>
using namespace std;

class array
{
    int *A;
    int size;
    int length;

public:
    array()
    {
        size=10;
        input();
    }
    array(int sz)
    {
        size = sz;
        A = new int[size];
        cout << "Enter the Length of the Array\n";
        cin >> length;
        for (int i = 0; i < length; i++)
        {
            cin >> A[i];
        }
    }
    ~array()
    {
        delete[] A;
    }
    void display();
    void input();
    void insert(int index, int x);
};

void array::input()
{
    A= new int[size];
    cout <<"\nEnter the Length of the Array\n";
    cin >>length;
    cout <<"Enter the Elements of the Array\n";
    for (int i = 0; i < length; i++)
    {
        cin >>A[i];
    }
}
void array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout <<A[i]<<" ";
    }
}

void array::insert(int index, int x)
{
    if (index >=0 && index < length)
    {
        for (int i = length; i > index; i--)
        {
            A[i]=A[i-1];// Naye wale mai purana wala store karna hai.
        }
        A[index]=x;
        length++;
    }
    
}
int main()
{
    array *arr3;
    array arr1(10);// invoking a parametized Constructor
    //array arr2;// Invoking a Default Constructor
    cout <<"Displaying the arr1 object\n";
    arr1.display();

    arr3= new array;// This is the method of creating the object dynamically in the heap memory.  

    //cout <<"\nDisplaying the arr2 object\n";
    //arr2.display();
    cout <<"\n";
    arr1.insert(3, 10);// Inserting 10 at the index 3
    arr1.display();
    cout <<"\n";
    
    arr3->insert(2, 15);
    arr3->display();
    arr3->~array();

    arr1.~array(); // Destructor frees the dynamic memory.

    return 0;
}
