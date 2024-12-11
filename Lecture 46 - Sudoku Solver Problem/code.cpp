#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, int dig)
{
    // Horigontal
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == dig)
        {
            return false;
        }
    }

    // Vertical
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == dig)
        {
            return false;
        }
    }

    // Grid
    int sRow = (row / 3) * 3;
    int sCol = (col / 3) * 3;
    for (int i = sRow; i <= sRow + 2; i++)
    {
        for (int j = sCol; j <= sCol + 2; j++)
        {
            if (board[i][j] == dig)
            {
                return false;
            }
        }
    }
    return true;
}

bool helper(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
    {
        return true;
    }

    int nextR = row;
    int nextC = col + 1;
    if (nextC == 9)
    {
        nextR = row + 1;
        nextC = 0;
    }

    if (board[row][col] != '.')
    {
        return helper(board, nextR, nextC);
    }

    // Place the digit
    for (char i = '1'; i <= '9'; i++)
    {
        if (isSafe(board, row, col, i))
        {
            board[row][col] = i;
            if (helper(board, nextR, nextC))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

// https://leetcode.com/problems/sudoku-solver/
void solveSudoku(vector<vector<char>> &board) // Time: O(9^(n*n)), Space: O(n*n)
{
    helper(board, 0, 0);
}

int main()
{

    return 0;
}