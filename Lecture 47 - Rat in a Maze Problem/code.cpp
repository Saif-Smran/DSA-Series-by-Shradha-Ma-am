#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &m, int r, int c, string path, vector<string> &ans)
{
    int n = m.size();
    // Base Case
    if (r < 0 || c < 0 || r >= n || c >= n || m[r][c] == 0 || m[r][c] == -1)
    {
        return;
    }
    // Destination
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(path);
        return;
    }

    m[r][c] = -1; // Mark Visited
    // Recursive Case
    helper(m, r + 1, c, path + "D", ans); // Down
    helper(m, r, c - 1, path + "L", ans); // Left
    helper(m, r, c + 1, path + "R", ans); // Right
    helper(m, r - 1, c, path + "U", ans); // Up
    m[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &m)
{
    vector<string> ans;
    string path = "";

    helper(m, 0, 0, path, ans);
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    vector<string> res = findPath(mat);
    for (string s : res)
    {
        cout << s << endl;
    }

    return 0;
}