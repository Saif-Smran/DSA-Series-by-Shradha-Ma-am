#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    // Top
    for (int i = 0; i < n; i++)
    {
        // star
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < 2 * (n - 1 - i); j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // Bottom
    for (int i = 0; i < n; i++)
    {
        // Star
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }

        // Space
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }

        // Star
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}