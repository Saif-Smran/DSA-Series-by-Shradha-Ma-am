// Pair Sum
#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target) //(Brute Force)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> pairSumOp(vector<int> nums, int target) // Optimum
{
    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum > target)
        {
            j--;
        }
        else if (pairSum < target)
        {
            i++;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;
    vector<int> ans = pairSumOp(nums, target);
    cout << ans[0] << " , " << ans[1] << endl;
    return 0;
}