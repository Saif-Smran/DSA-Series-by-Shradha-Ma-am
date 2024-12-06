#include <iostream>
#include <vector>
using namespace std;

void getPerm(vector<int> &nums, int idx, vector<vector<int>> &ans) // TC : n!
{
    if (idx == nums.size())
    {
        ans.push_back(nums); // Push the current permutation into ans
        return;              // Missing semicolon fixed
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);    // Swap elements to generate new permutation
        getPerm(nums, idx + 1, ans); // Recur for the next index
        swap(nums[idx], nums[i]);    // Backtrack to restore the original state
    }
}

// https://leetcode.com/problems/permutations
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    getPerm(nums, 0, ans);
    return ans;
}

int main()
{

    return 0;
}