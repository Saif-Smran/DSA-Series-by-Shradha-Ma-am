// Using Kadane's Algorithm
// Maximum Subarray Sum
#include <iostream>
#include <climits>  // Include this header for INT_MIN
using namespace std;

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = 7;

    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << "Maximum Subarray Sum = " << maxSum << endl;
    return 0;
}
