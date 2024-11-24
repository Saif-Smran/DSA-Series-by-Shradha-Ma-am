#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/

int subarraySumB(vector<int> &nums, int k) // Approach 1 O(n^2) - Brute Force
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) // Starting point of subarray
    {
        int sum = 0;
        for (int j = i; j < n; j++) // Ending point of subarray
        {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

int subarraySum(vector<int> &arr, int k) // Approach 2 O(n) - Prefix Sum + Hashmap
{
    int n = arr.size();
    int count = 0;
    vector<int> prefixSum(n, 0);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    unordered_map<int, int> m; // PS , Feq
    for (int j = 0; j < n; j++)
    {
        if (prefixSum[j] == k)
            count++;

        int val = prefixSum[j] - k;

        if (m.find(val) != m.end())
            count += m[val];

        if (m.find(prefixSum[j]) == m.end())
            m[prefixSum[j]] = 0;

        m[prefixSum[j]]++;
    }
    return count;
}

int main()
{

    return 0;
}