#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/3sum/

vector<vector<int>> threeSumB(vector<int> &nums) // Approach 1: O(n^3) Brute Force
{
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> s; // Unique vector sets

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> trp = {nums[i], nums[j], nums[k]};
                    sort(trp.begin(), trp.end());

                    if (s.find(trp) == s.end())
                    {
                        s.insert(trp);
                        ans.push_back(trp);
                    }
                }
            }
        }
    }

    return ans;
}

vector<vector<int>> threeSumH(vector<int> &nums) // Approach 2: O(n^2) Hashing
{
    int n = nums.size();

    set<vector<int>> uniqueTriplets; // Unique vector sets

    for (int i = 0; i < n; i++)
    {
        int tar = -nums[i]; // Corrected: target should be -nums[i]
        set<int> s;         // Set to track seen numbers for the current i
        for (int j = i + 1; j < n; j++)
        {
            int third = tar - nums[j];

            if (s.find(third) != s.end())
            {
                vector<int> trp = {nums[i], nums[j], third};
                sort(trp.begin(), trp.end());
                uniqueTriplets.insert(trp); // Store unique triplets
            }
            s.insert(nums[j]); // Mark nums[j] as seen
        }
    }

    // Convert set to vector
    vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());

    return result;
}

vector<vector<int>> threeSum(vector<int> &nums) // Approach 3: O(n^2) Two Pointer 
{
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1])
                    j++;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}