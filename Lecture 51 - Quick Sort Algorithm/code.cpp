#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int pivot = arr[end];
    int idx = st - 1;

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end) // TC: O(nlogn) on average, O(n^2) in worst case and SC: O(1)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx - 1);  // sort left side
        quickSort(arr, pivIdx + 1, end); // sort right side
    }
}

int main()
{
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    quickSort(arr, 0, arr.size() - 1);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}