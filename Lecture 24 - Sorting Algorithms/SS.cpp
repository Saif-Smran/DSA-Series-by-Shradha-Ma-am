// Selection Sort
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) // T: O(n^2) S: O(1)
{
    for (int i = 0; i < n - 1; i++) // T: O(n)
    {
        int smallestIndex = i; // Unsorted part first element
        for (int j = i + 1; j < n; j++) // T: O(n)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
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

    selectionSort(arr, n);

    printArr(arr, n);

    return 0;
}