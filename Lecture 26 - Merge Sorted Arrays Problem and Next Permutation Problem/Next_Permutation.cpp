#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &A)
    {
        int piv = -1, n = A.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i] < A[i + 1])
            {
                piv = i;
                break;
            }
        }
        if (piv == -1)
        {
            reverse(A.begin(), A.end());
            return;
        }
        for (int i = n - 1; i > piv; i--)
        {
            if (A[i] > A[piv])
            {
                swap(A[i], A[piv]);
                break;
            }
        }

        // reverse(A.begin() + piv + 1, A.end());

        int i = piv + 1, j = n - 1;
        while (i <= j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
};

int main()
{
    /* code */
    return 0;
}
