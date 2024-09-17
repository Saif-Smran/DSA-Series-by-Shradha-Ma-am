#include <iostream>
using namespace std;

int fact(int n){
    int fact=1;
    for (int i = 1; i <=n; i++)
    {
        fact*=i;
    }
    return fact;
}

int main()
{
    int n=7,r=2;
    int sum = fact(n)/(fact(r)*fact(n-r));
    cout<<sum<<endl;
    return 0;
}