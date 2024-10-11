// Insertion Sort
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) // T: O(n^2) S: O(1)
{
    for (int i = 1; i < n; i++) // T: O(n)
    {
        int curr = arr[i]; // Element to be inserted
        int previous = i - 1; // Last element of sorted part
        while (previous >= 0 && arr[previous] > curr) // T: O(n)
        {
            arr[previous + 1] = arr[previous];
            previous--;
        }
        arr[previous + 1] = curr; // Insert the element
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

    insertionSort(arr, n);

    printArr(arr, n);

    return 0;
}