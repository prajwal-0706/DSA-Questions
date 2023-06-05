#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Value of 'n' :- ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        char value = 'A' + i - 1;
        for (int j = 1; j <= n; j++)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            char value = 'A' + j - 1;
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;

    char v = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << v++ << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        char value = 'A' + i - 1;
        for (int j = 1; j <= n; j++)
        {
            cout << value++ << " ";
        }
        cout << endl;
    }

    cout << endl;

    char val = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << val << " ";
        }
        val++;
        cout << endl;
    }

    return 0;
}