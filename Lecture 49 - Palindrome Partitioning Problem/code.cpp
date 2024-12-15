#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrom(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

void getAllParts(string s, vector<string> &partition, vector<vector<string>> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(partition);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string part = s.substr(0, i + 1);
        if (isPalindrom(part))
        {
            partition.push_back(part);
            getAllParts(s.substr(i + 1), partition, ans);
            partition.pop_back();
        }
    }
}

// https://leetcode.com/problems/palindrome-partitioning/
vector<vector<string>> partition(string s) // Time: O(n*2^n), Space: O(n)
{
    vector<vector<string>> ans;
    vector<string> partitions;
    getAllParts(s, partitions, ans);

    return ans;
}

int main()
{

    return 0;
}