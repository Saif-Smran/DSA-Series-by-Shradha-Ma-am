#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/search-a-2d-matrix/
bool searchMatrix1(vector<vector<int>> &matrix, int target) // Approach 1: log(m*n)
{
    // Binary Search in Total Matrix
    int m = matrix.size(), n = matrix[0].size();

    int startRow = 0, endRow = m - 1, midRow;
    while (startRow <= endRow)
    {
        midRow = startRow + (endRow - startRow) / 2;
        if (matrix[midRow][0] <= target && matrix[midRow][n - 1] >= target)
        {
            break;
        }
        else if (matrix[midRow][n - 1] < target)
        {
            startRow = midRow + 1;
        }
        else if (matrix[midRow][0] > target)
        {
            endRow = midRow - 1;
        }
    }

    int startCol = 0, endCol = n - 1;
    while (startCol <= endCol)
    {
        int midCol = startCol + (endCol - startCol) / 2;
        if (matrix[midRow][midCol] == target)
        {
            return true;
        }
        else if (matrix[midRow][midCol] < target)
        {
            startCol = midCol + 1;
        }
        else if (matrix[midRow][midCol] > target)
        {
            endCol = midCol - 1;
        }
    }
    return false;
}
// https://leetcode.com/problems/search-a-2d-matrix-ii/
bool searchMatrix2(vector<vector<int>> &matrix, int target) // Approach 2: O(m+n)
{
    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = n - 1;
    while (c >= 0 && r < m)
    {
        if (target == matrix[r][c])
        {
            return true;
        }
        else if (target < matrix[r][c])
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix1 = {{1, 3, 5, 7},
                                   {10, 11, 16, 20},
                                   {23, 30, 34, 60}};
    int target1 = 3;
    cout << (searchMatrix1(matrix1, target1) ? "Found" : "Not Found") << endl;

    vector<vector<int>> matrix2 = {{1, 3, 5, 7},
                                   {10, 11, 16, 20},
                                   {23, 30, 34, 60}};
    int target2 = 3;
    cout << (searchMatrix2(matrix2, target2) ? "Found" : "Not Found") << endl;
    return 0;
}
