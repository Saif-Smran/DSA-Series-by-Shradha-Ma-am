#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/two-sum/
vector<int> twoSum(vector<int> &arr, int tar) // O(n)
{
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) // O(n)
    {
        int first = arr[i];
        int sec = tar - first;

        if (m.find(sec) != m.end()) // O(1)
        {
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }
        m[first] = i;
    }
    return ans;
}

// https://leetcode.com/problems/find-the-duplicate-number/
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) // O(n^2)
{
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a, b;
    int exsum = (n * n * (n * n + 1)) / 2, acsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            acsum += grid[i][j];
            if (s.find(grid[i][j]) != s.end())
            {
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    b = exsum + a - acsum;
    ans.push_back(b);
    return ans;
}

// https://leetcode.com/problems/find-the-duplicate-number/
int findDuplicate(vector<int> &nums) // O(n)
{
    int slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];       //+1
        fast = nums[nums[fast]]; //+2
    } while (slow != fast);
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow]; //+1
        fast = nums[fast]; //+1
    }

    return slow;
}

int main()
{

    return 0;
}