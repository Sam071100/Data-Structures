#include <iostream>
using namespace std;

template<class T>// Generic Class Type
class array
{
private:
    T *A;
    int size;
    int length;
public:
    array()
    {
        size= 10;
        A= new T[10];
        length =0;
    }
    array(int sz)
    {
        size= sz;
        length= 0;
        A= new T[size];
    }
    ~array()
    {
        delete []A;
    }
    void Display();
    void Insert(int index, T x);
    T Delete(int index);
};

template<class T>
void array<T>:: Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}
template<class T>
void array<T>::Insert(int index, T x)
{
    if (index >=0 && index <= length)
    {
        for (int i = length-1; i >= index; i--)
        {
            A[i+1]=A[i];
        }
        A[index]=x;
        length++;
    }
}

template<class T>
T array<T>::Delete(int index)
{
    T x=0;
    if (index >= 0 && index <= length)
    {
        x= A[index];// it stores the element which is going to be deleted.
        for (int i = index; i < length-1; i++)
        {
            A[i]=A[i+1];// Aage wala ek piche shift karna hai
        }
        length--;
    }
    return x;
}
int main()
{
    array<char>arr(10);// Here the datatype is char.

    arr.Insert(0,'a');
    arr.Insert(1,'b');
    arr.Insert(2,'c');
    arr.Insert(3,'d');
    arr.Insert(4,'e');
    arr.Display();
    cout <<"The element which is going to be Deleted is : ";
    cout <<arr.Delete(0)<<endl;
    arr.Display();

    return 0;
}
