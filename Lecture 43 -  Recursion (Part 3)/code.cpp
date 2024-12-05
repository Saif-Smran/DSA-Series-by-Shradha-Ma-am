#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Print all the subsets of a array using recursion
void printSubset(vector<int> &arr, vector<int> &ans, int idx = 0) // TC: O(n x 2^n) SC: O(n)
{
    if (idx == arr.size())
    {
        for (auto &i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    // Pick the element
    ans.push_back(arr[idx]);
    printSubset(arr, ans, idx + 1);

    // Don't pick the element
    ans.pop_back();
    printSubset(arr, ans, idx + 1);
}

// https://www.leetcode.com/problems/subsets/
void allsubset(vector<int> &arr, vector<int> &ans, int idx, vector<vector<int>> &subs) // To store all subsets
{
    if (idx == arr.size())
    {
        subs.push_back(ans);
        return;
    }

    // Include the current element
    ans.push_back(arr[idx]);
    allsubset(arr, ans, idx + 1, subs);

    // Exclude the current element
    ans.pop_back();
    allsubset(arr, ans, idx + 1, subs);
}

vector<vector<int>> subsets(vector<int> &nums) // TC: O(n x 2^n) SC: O(2^n)
{
    vector<vector<int>> subs; // To store all subsets
    vector<int> ans;          // To store a single subset
    allsubset(nums, ans, 0, subs);
    return subs;
}

// https://www.leetcode.com/problems/subsets-ii/
void allsubsetu(vector<int> &arr, vector<int> &ans, int idx, vector<vector<int>> &subs) // To store all subsets
{
    if (idx == arr.size())
    {
        subs.push_back(ans);
        return;
    }

    // Include the current element
    ans.push_back(arr[idx]);
    allsubsetu(arr, ans, idx + 1, subs);

    // Backtrack
    ans.pop_back();

    int i = idx + 1;
    while (i < arr.size() && arr[i] == arr[i - 1])
        i++;
    
    // Exclude the current element
    allsubsetu(arr, ans, i, subs);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) // TC: O(n x 2^n) SC: O(2^n)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> subs; // To store all subsets
    vector<int> ans;          // To store a single subset
    allsubsetu(nums, ans, 0, subs);
    return subs;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    printSubset(arr, ans);

    return 0;
}