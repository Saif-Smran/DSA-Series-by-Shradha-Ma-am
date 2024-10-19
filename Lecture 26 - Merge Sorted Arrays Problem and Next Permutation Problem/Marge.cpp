#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int m, vector<int> &B, int n) // TC O(m+n)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (A[i] >= B[j])
        {
            A[idx] = A[i];
            i--;
        }
        else
        {
            A[idx] = B[j];
            j--;
        }
        idx--;
    }
    while (j >= 0)
    {
        A[idx] = B[j];
        j--;
        idx--;
    }
}

int main()
{
    /* code */
    return 0;
}
