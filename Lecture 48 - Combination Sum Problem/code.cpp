#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;
void helper(vector<int> &arr, int i, vector<int> &comb, vector<vector<int>> &ans, int tar)
{
    // Base Case
    if (i == arr.size() || tar < 0)
    {
        return;
    }
    if (tar == 0)
    {
        if (s.find(comb) == s.end())
        {
            ans.push_back(comb);
            s.insert(comb);
        }
        return;
    }

    comb.push_back(arr[i]);
    helper(arr, i + 1, comb, ans, tar - arr[i]); // Single
    helper(arr, i, comb, ans, tar - arr[i]);     // Multiple
    comb.pop_back();                             // Backtrack
    helper(arr, i + 1, comb, ans, tar);          // Skip
}

// https://leetcode.com/problems/combination-sum/
vector<vector<int>> combinationSum(vector<int> &arr, int target) // TC : O(2^N) SC : O(N)
{
    vector<vector<int>> ans;
    vector<int> comb;
    helper(arr, 0, comb, ans, target);
    return ans;
}

int main()
{

    return 0;
}