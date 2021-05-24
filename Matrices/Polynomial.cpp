#include <iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void Create(struct Poly *p)
{
    cout <<"Number of terms\n";
    cin >>p->n;
    p->terms = new Term[p->n];
    // p->terms=(struct Term*)malloc(p->n*sizeof(struct Terms)); IN C LANGUAGE
    cout <<"Enter Terms\n";
    for (int i = 0; i < p->n; i++)
    {
        cin >>p->terms[i].coeff>>p->terms[i].exp;
    }
}

void Display(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout <<p.terms[i].coeff<<"x"<<p.terms[i].exp<<" + ";
    }
    cout <<endl;
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i,j,k;
    struct Poly *sum;
    sum = new Poly;// sum=(struct Poly*)malloc(sizeof(struct Poly));
    sum->terms= new Term[p1->n + p2->n];
    i=j=k=0;
    while (i<p1->n && j<p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
        {
            sum->terms[k++] = p1->terms[i++];
        }
        else if (p1->terms[i].exp < p2->terms[j].exp)
        {
            sum->terms[k++] = p2->terms[j++];
        }
        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    for ( ; i < p1->n; i++)
    {
        sum->terms[k++] = p1->terms[i];
    }
    for ( ; j < p2->n; j++)
    {
        sum->terms[k++] = p2->terms[j];
    }
    sum->n= k;

    return sum;
}

int main()
{
    struct Poly p1,p2,*p3;

    Create(&p1);
    Create(&p2);
    p3 = add(&p1, &p2);
    cout <<endl;
    Display(p1);
    cout <<endl;
    Display(p2);
    cout <<endl;
    Display(*p3);
    
    return 0;
}
