// Majority Element

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElementB(vector<int> &nums) // Brute Force
{
    int n = nums.size();

    for (int val : nums)
    {
        int feq = 0;
        for (int el : nums)
        {
            if (el == val)
            {
                feq++;
            }
        }
        if (feq > n / 2)
        {
            return val;
        }
    }
    return -1;
}

int majorityElementO(vector<int> &nums) // Optimal approce
{
    int n = nums.size();

    // Sort
    sort(nums.begin(), nums.end());

    // Frequency Count
    int feq = 1, ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            feq++;
        }
        else
        {
            feq = 1;
            ans = nums[i];
        }
        if (feq > n / 2)
        {
            return ans;
        }
    }

    return ans;
}

int majorityElementM(vector<int> &nums) // Moore's Voting Algorithm
{
    int n = nums.size();

    int feq = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (feq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            feq++;
        }
        else
        {
            feq--;
        }
    }

    int count = 0;
    for (int val : nums)
    {
        if (val == ans)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

int main()
{

    return 0;
}