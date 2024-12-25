#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;
    while (i <= mid && j <= end) // merge the two halves
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            invCount += mid - i + 1; // count the inversions
        }
    }
    // if elements are left in the first half
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    // if elements are left in the second half
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++) // copy the sorted elements to the original array
    {
        arr[idx + st] = temp[idx];
    }
    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2; // to avoid overflow

        int leftInvCount = mergeSort(arr, st, mid);       // return the inversions in the left half
        int righrInvCount = mergeSort(arr, mid + 1, end); // return the inversions in the right half

        int invCounr = merge(arr, st, mid, end); // return the inversions in the current merge
        return leftInvCount + righrInvCount + invCounr;
    }
    return 0;
}

int main()
{
    vector<int> arr = {12, 31, 35, 2, 8, 32, 5, 17};
    cout << "Inversition count : " << mergeSort(arr, 0, arr.size() - 1) << endl;

    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}