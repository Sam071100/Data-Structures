#include <iostream>
using namespace std;
// Diagonal Matrix
int main()
{
    int *A, n, ch, x;
    cout << "Enter the dimension\n";
    cin >> n;
    A = new int[n];
    do
    {
        cout << "DISPLAYING MENU\n\n";
        cout << "Select any choice and proceed\n";
        cout << "1. Create\n";
        cout << "2. Get\n";
        cout << "3. Set\n";
        cout << "4. Display\n";
        cout << "5.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the Diagonal elements of the matrix\n";
            for (int i = 1; i <= n; i++)
            {
                cin >> A[i - 1];
            }
            break;
        case 2:
            cout << "Enter the indicies\n";
            int i, j;
            cin >> i >> j;
            if (i == j)
            {
                cout << A[i - 1];
            }
            else
            {
                cout << "0\n";
            }

            break;
        case 3:
            cout << "Enter the row, column and the element\n";
            cin >> i >> j >> x;
            if (i == j)
            {
                A[i - 1] = x;
            }
            break;
        case 4:
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                    {
                        cout << A[i - 1]<<" ";
                    }
                    else
                    {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }
            break;
        case 5:
            return 0;
        default:
            cout << "Wrong choice Selected, Please try agian..!\n";
            break;
        }
    } while (1 == 1);

    return 0;
}
