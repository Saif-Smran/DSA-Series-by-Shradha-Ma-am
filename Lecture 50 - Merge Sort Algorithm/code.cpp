#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
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
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2; // to avoid overflow

        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half

        merge(arr, st, mid, end); // merge the two halves
    }
}

int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    mergeSort(arr, 0, arr.size() - 1);
    
    for(int val: arr)
    {
        cout << val << " ";
    }

    return 0;
}