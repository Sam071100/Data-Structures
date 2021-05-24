#include <iostream>
using namespace std;

struct Element
{
    int i; // row
    int j; // column
    int x; // element
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void Create(struct Sparse *s)
{
    cout << "Enter Dimensions\n";
    cin >> s->m >> s->n;
    cout << "Number of non-zero elements\n";
    cin >> s->num;
    s->ele = new Element[s->num]; // Array of type element and size num.
    cout << "Enter all the Non-Zero elements\n";
    for (int i = 0; i < s->num; i++)
    {
        cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x; // please check the diagram in the notebook for further reference.
    }
}

void Display(struct Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
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
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)// This function returns the address of the sum matrix created in the heap. So a pointer should be created in the main() for taking this address here in this case *s3.
{
    if (s1->m != s2->m && s1->n != s2->n)
    {
        return 0; // Both matrix is of not equal order.
    }

    struct Sparse *sum;
    sum = new Sparse;
    sum->ele = new Element[s1->num + s2->num];
    int i = 0, j = 0, k = 0;

    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i) // Here rows no. are compared
        {
            sum->ele[k++] = s1->ele[i++];
        }
        else if (s1->ele[i].i > s2->ele[j].i)
        {
            sum->ele[k++] = s2->ele[j++];
        }
        else
        {
            if (s1->ele[i].j < s2->ele[j].j) // if rows no. are same then the column no. is compared.
            {
                sum->ele[k++] = s1->ele[i++];
            }
            else if (s1->ele[i].j > s2->ele[j].j)
            {
                sum->ele[k++] = s2->ele[j++];
            }
            else
            {
                sum->ele[k] = s1->ele[i++]; // If both the rows no. and columns no. are same
                sum->ele[k++].x += s2->ele[j++].x;
            }
        }
    }
    // If any of the matrix is finshed so the other remaining matrix has to be copied into the sum matrix. So,
    for (; i < s1->num; i++)
    {
        sum->ele[k++] = s1->ele[i];
    }
    for (; j < s2->num; j++)
    {
        sum->ele[k++] = s2->ele[j];
    }
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;// k keeps the track of non-zero elements.
    return sum;
}

int main()
{
    struct Sparse s1,s2,*s3;
    cout <<"Creating the Matrix1\n";
    Create(&s1);
    cout <<"Creating the Matrix2\n";
    Create(&s2);
    s3 = add(&s1, &s2);
    cout <<"Displaying the First Matrix\n";
    Display(s1);
    cout <<"\nDisplaying the Second Matrix\n";
    Display(s2);
    cout <<"\nDisplaying the Sum of the Matrix1 and Matrix2\n";
    Display(*s3);// As this was a pointer so derefrencing it.
    return 0;
}
