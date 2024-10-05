#include <iostream>
#include <vector>
using namespace std;

// Check if mid is a valid answer or not
bool isValid(vector<int> &arr, int n, int m, int maximumAllowedPages) // Time Complexity: O(n) Space Complexity: O(1)
{
    int student = 1;
    int pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maximumAllowedPages) // If any book has more pages than maximum allowed pages
        {
            return false;
        }
        if (pages + arr[i] <= maximumAllowedPages) // If pages are less than or equal to maximum allowed pages
        {
            pages += arr[i];
        }
        else // If pages are more than maximum allowed pages
        {
            student++;
            pages = arr[i];
        }
    }
    return student > m ? false : true; // If number of students are more than m return false else return true
}

int allocateBooks(vector<int> &arr, int n, int m) // Time Complexity: O(nlog(sum of all books)) Space Complexity: O(1)
{
    // edge case
    if (m > n) // If number of students are more than number of books
    {
        return -1;
    }
    // calculate sum of all books
    int sum = 0;
    for (int i = 0; i < n; i++) // Time Complexity: O(n)
    {
        sum += arr[i];
    }
    // binary search
    int st = 0, end = sum, ans = -1; // Possible range of answer
    while (st <= end)                // Time Complexity: O(log(sum of all books))
    {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) // If mid is a valid answer if valid go to left part
        {
            ans = mid;
            end = mid - 1;
        }
        else // If mid is not a valid answer go to right part
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // vector<int> arr = {2, 1, 3, 4}; // 6
    // int n = 4, m = 5;
    vector<int> arr = {15,17,20}; // 32
    int n = 3, m = 2;
    cout << allocateBooks(arr, n, m) << endl;

    return 0;
}