// Using Brute force
// Maximum Subarray Sum
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(arr) / sizeof(int);

    int maxSum = INT_MIN;
    for (int st = 0; st < n; st++)
    {
        int currSum = 0;
        for (int end = st; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout << "Maximum Subarray Sum = " << maxSum << endl;
    return 0;
}