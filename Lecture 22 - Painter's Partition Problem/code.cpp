#include <iostream>
#include <vector>
using namespace std;

// Is it possible to paint the board with given time
bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime) // T: O(n) S: O(1)
{
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= maxAllowedTime) // if current painter can paint the board
        {
            time += arr[i];
        }
        else // if current painter can't paint the board
        {
            painters++;
            time = arr[i];
        }
    }
    return painters <= m ? true : false;
}
// Painters Partition Problem
int minTimeToPaint(vector<int> &arr, int n, int m) // T: O(nlog(sum)) S: O(1)
{
    // find the max element and sum of all elements
    int sum = 0, maxVal = INT_MIN;
    for (int i = 0; i < n; i++) // T: O(n) S: O(1)
    {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    // binary search
    int st = maxVal, end = sum, ans = -1;
    while (st <= end) // T: O(nlog(sum)) S: O(1)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid)) // Left side
        {
            ans = mid;
            end = mid - 1;
        }
        else // Right side
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {40, 30, 10, 20};
    int n = 4, m = 2;

    cout << minTimeToPaint(arr, n, m) << endl;

    return 0;
}