#include <iostream>
using namespace std;

struct rectangle
{
    int length;
    int breadth;
};
int main()
{
    struct rectangle *r;
    struct rectangle p;
    p.breadth=5;
    r= new struct rectangle[sizeof(struct rectangle)];
    r->length=5;
    cout <<p.breadth<<endl;
    cout <<r->length<<endl;
    return 0;
}
