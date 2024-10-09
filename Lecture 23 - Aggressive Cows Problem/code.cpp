#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Is it possible to place cows with given distance
bool isPossible(vector<int> &arr, int n, int c, int mid) // T: O(nlogn) S: O(1)
{
    sort(arr.begin(), arr.end());
    int cows = 1, lastStallPos = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - lastStallPos >= mid) // if current cow can be placed
        {
            cows++;
            lastStallPos = arr[i];
        }
        if (cows == c)
            return true;
    }
    return false;
}

// Aggressive Cows Problem
int getMinDistance(vector<int> &arr, int n, int c) // T: O(nlogn) S: O(1)
{
    // find the max and min value in the array
    int maxValInArr = INT_MIN, minValInArr = INT_MAX;
    for (int i = 0; i < n; i++) // T: O(n) S: O(1)
    {
        maxValInArr = max(maxValInArr, arr[i]);
        minValInArr = min(minValInArr, arr[i]);
    }
    // Binary Search
    int st = 1, end = maxValInArr - minValInArr, ans = -1;
    while (st <= end) // T: O(nlogn) S: O(1)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, c, mid)) // Left side
        {
            ans = mid;
            st = mid + 1;
        }
        else // Right side
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 5, c = 3;
    vector<int> arr = {1, 2, 8, 4, 9};
    cout << getMinDistance(arr, n, c) << endl;
    return 0;
}