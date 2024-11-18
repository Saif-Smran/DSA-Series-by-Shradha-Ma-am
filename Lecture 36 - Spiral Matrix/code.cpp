#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/
vector<int> spiralOrder(vector<vector<int>> &matrix) // Time: O(m*n) | Space: O(1)
{
    int m = matrix.size(), n = matrix[0].size();
    int srow = 0, scol = 0;
    int erow = m - 1, ecol = n - 1;
    vector<int> ans;

    while (srow <= erow && scol <= ecol)
    {

        // Top
        for (int j = scol; j <= ecol; j++)
        {
            ans.push_back(matrix[srow][j]);
        }

        // Right
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(matrix[i][ecol]);
        }

        // Bottom
        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow)
                break;
            ans.push_back(matrix[erow][j]);
        }

        // Left
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if (scol == ecol)
                break;
            ans.push_back(matrix[i][scol]);
        }

        srow++;
        scol++;
        erow--;
        ecol--;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};
    vector<int> ans = spiralOrder(matrix);
    for (int ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}