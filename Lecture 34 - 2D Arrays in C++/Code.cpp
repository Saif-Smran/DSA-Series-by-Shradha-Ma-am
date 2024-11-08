#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Linear Search in 2D Array (Matrix) using pair
pair<int, int> linearSearch(int matrix[][3], int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == key)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// Max row sum
int maxRowSum(int matrix[][3], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// Max col sum
int maxColSum(int matrix[][3], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < cols; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += matrix[j][i];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// Diagonal sum of matrix O(n2)
int diagonalSumn2(int matrix[][3], int rows, int cols)
{
    int sum = 0;
    int n = rows;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) // Primary Diagonal
            {
                sum += matrix[i][j];
            }
            else if (j == n - 1 - i) // Secondary Diagonal
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

// Diagonal sum of matrix O(n)
int diagonalSumn(int matrix[][3], int rows, int cols)
{
    int sum = 0;
    int n = rows;
    // P.D -> i == j
    // S.D -> j == n - 1 - i

    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i]; // Primary Diagonal
        if(i != n - 1 - i)
            sum += matrix[i][n - 1 - i]; // Secondary Diagonal
    }
    
    return sum;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // 3x3 matrix
    int rows = 3;
    int cols = 3;
    int key = 11;

    // Input
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cin >> matrix[i][j];
    //     }
    // }

    // Output
    //  for (int i = 0; i < rows; i++)
    //  {
    //      for (int j = 0; j < cols; j++)
    //      {
    //          cout << matrix[i][j] << " ";
    //      }
    //      cout << endl;
    //  }

    // Linear Search
    // pair<int, int> p = linearSearch(matrix, rows, cols, 0);
    // if (p.first == -1 && p.second == -1)
    // {
    //     cout << "Element not found" << endl;
    // }
    // else
    // {
    //     cout << "Element found at index: " << p.first << " " << p.second << endl;
    // }

    cout << "Diagonal Sum: " << diagonalSumn(matrix, rows, cols) << endl;

    return 0;
}