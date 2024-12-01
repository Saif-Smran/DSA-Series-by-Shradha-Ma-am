#include <iostream>
#include <vector>
using namespace std;

// Fibonachi series using recursion
//  https://www.leetcode.com/problems/fibonacci-number/
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// Check if a array is sorted or not using recursion

bool isSorted(vector<int> arr, int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }

    return arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1);
}

// Binary search using recursion
int binarySearch(vector<int> arr, int tar, int start, int end)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == tar)
    {
        return mid;
    }
    else if (arr[mid] > tar)
    {
        return binarySearch(arr, tar, start, mid - 1);
    }
    else
    {
        return binarySearch(arr, tar, mid + 1, end);
    }
}

// https://www.leetcode.com/problems/binary-search/
int search(vector<int> &nums, int target)
{
    return binarySearch(nums, target, 0, nums.size() - 1);
}

int main()
{

    return 0;
}