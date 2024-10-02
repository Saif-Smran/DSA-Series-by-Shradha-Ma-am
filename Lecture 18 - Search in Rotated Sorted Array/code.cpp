#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int st = 0, end = nums.size() - 1, mid;

    while (st <= end)
    {
        mid = st + (end - st) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[st] <= nums[mid]) // Left Sorted
        {
            if (nums[st] <= target && target <= nums[mid])
            {
                end = mid - 1; // Left
            }
            else
            {
                st = mid + 1; // Right
            }
        }
        else // Right Sorted
        {
            if (nums[mid] <= target && target <= nums[end])
            {
                st = mid + 1; // Right
            }
            else
            {
                end = mid - 1; // Left
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}