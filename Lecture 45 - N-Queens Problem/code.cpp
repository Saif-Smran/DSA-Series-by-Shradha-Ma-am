#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n) // TC: O(n)
{
    // Horizontal
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
        {
            return false;
        }
    }
    // Vartical
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    // Left Dioginal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    // Right Dioginal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back({board});
        return;
    }

    for (int j = 0; j < n; j++)
    {

        if (isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.';
        }
    }
}

// https://leetcode.com/problems/n-queens/
vector<vector<string>> solveNQueens(int n) // TC: O(n^n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nQueens(board, 0, n, ans);
    return ans;
}

int main()
{

    return 0;
}