#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelfB(vector<int> &nums) // Brute Force
{
    vector<int> ans(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (j != i)
            {
                ans[i] *= nums[j];
            }
        }
    }
    return ans;
}

vector<int> productExceptSelfOtc(vector<int> &nums) // O(n) TC & SC
{
    int n = nums.size();
    vector<int> ans(n, 1);
    vector<int> suff(n, 1);
    vector<int> pre(n, 1);
    // Prefix
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] * nums[i - 1];
    }
    // Suffiex
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] * nums[i + 1];
    }
    // Answer
    for (int i = 0; i < n; i++)
    {
        ans[i] = pre[i] * suff[i];
    }
    return ans;
}

vector<int> productExceptSelfOP(vector<int> &nums) // O(n) TC & O(1) SC
{
    int n = nums.size();
    vector<int> ans(n, 1);
    // Prefix
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    // Suffiex
    int suff = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suff *= nums[i + 1];
        ans[i] *= suff;
    }

    return ans;
}

int main()
{

    return 0;
}