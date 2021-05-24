#include <iostream>
using namespace std;

// Convering read and display into the operators using the insertiomn and extraction operator.
class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele; // Array of elements woh matrix 3 row wala diagram in notes
public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }
    // Operator overloading in C++ can be done either by using the member function or the friend function.
    Sparse operator+(Sparse &s);
    // Implementing the insertion and the extraction operator
    friend istream & operator>>(istream &is, Sparse &s); //read
    friend ostream & operator<<(ostream &os, Sparse &s); //display
};

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    if (m != s.m && n != s.n)
    {
        return Sparse(0,0,0);
    }

    Sparse *sum = new Sparse(m, n, num + s.num);
    i=j=k=0;// Mistake before I declared it where I defined it.
    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)
        {
            sum->ele[k++] = ele[i++];
        }
        else if (ele[i].i > s.ele[j].i)
        {
            sum->ele[k++] = s.ele[j++];
        }
        else
        {
            if (ele[i].j < s.ele[j].j)
            {
                sum->ele[k++] = ele[i++];
            }
            else if (ele[i].j > s.ele[j].j)
            {
                sum->ele[k++] = s.ele[j++];
            }
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }
    for ( ; i < num; i++)
    {
        sum->ele[k++] = ele[i];
    }
    for (; j < s.num; j++)
    {
        sum->ele[k++] = s.ele[j];
    }
    sum->num=k;// k is for keeping the track of the non-zero elements

    return *sum;
}
istream & operator>>(istream &is, Sparse &s) // Using the extraction operator
{
    cout << "Enter the Non-Zero elements\n";
    for (int i = 0; i < s.num; i++)
    {
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    return is;
}
ostream & operator<<(ostream &os, Sparse &s) // Using the insertion operator
{
    int k=0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.ele[k].i == i && s.ele[k].j == j)
            {
                cout << s.ele[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return os;
}

int main()
{
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);
    cin >> s1; // s1.Display();
    cin >> s2; // s2.Display();

    Sparse sum= s1 +s2;

    cout <<"First Matrix\n"<<s1;
    cout <<"Second Matrix\n"<<s2;
    cout <<"Sum of the Matrix\n"<<sum;
    s1.~Sparse();
    s2.~Sparse();

    return 0;
}
