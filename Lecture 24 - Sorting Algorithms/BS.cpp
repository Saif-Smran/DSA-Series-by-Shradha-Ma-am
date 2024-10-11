// Bubble Sort
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) // T: O(n^2) S: O(1)
{
    for (int i = 0; i < n - 1; i++) // T: O(n)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++) // T: O(n)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }

            if (!isSwapped)
            {
                return;
            }
        }
    }
}

void printArr(int arr[], int n) // T: O(n) S: O(1)
{
    for (int i = 0; i < n; i++) // T: O(n)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    int arr[] = {5, 4, 3, 2, 1};

    bubbleSort(arr, n);

    printArr(arr, n);

    return 0;
}