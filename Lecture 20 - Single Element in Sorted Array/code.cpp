#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &A)
    {
        // edge cases
        int n = A.size();
        if (A.size() == 1)
            return A[0];

        // binary search
        int st = 0, end = n - 1, mid;
        while (st <= end)
        {
            mid = st + (end - st) / 2;

            // edge cases
            if (mid == 0 && A[0] != A[1])
                return A[mid];
            if (mid == n - 1 && A[n - 2] != A[n - 1])
                return A[mid];

            // check if mid is the single element
            if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1])
                return A[mid];
            if (mid % 2 == 0) // Even index
            
            {
                if (A[mid - 1] == A[mid]) // Single element is on the right
                    end = mid - 1;
                else // Single element is on the left
                    st = mid + 1;
            }
            else // Odd index
            {
                if (A[mid - 1] == A[mid]) // Single element is on the left
                    st = mid + 1;
                else // Single element is on the right
                    end = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}