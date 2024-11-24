#include <iostream>
using namespace std;

// print n to 1 using recurtion
void printNto1(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printNto1(n - 1);
}

// N factorial using recurtion
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

// Sum of n natural numbers using recurtion
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printNto1(n);
    cout << endl;
    cout << "Factorial of "<< n << " is : ";
    cout << factorial(n) << endl;
    cout << "Sum of "<< n << " natural numbers is : ";
    cout << sum(n) << endl;
    
    return 0;
}