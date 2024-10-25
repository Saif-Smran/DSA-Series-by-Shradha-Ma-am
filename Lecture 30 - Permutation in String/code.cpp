#include <iostream>
#include <string>
using namespace std;
// Compare Freq of two Strings
bool isFreqSame(int feq1[], int feq2[]) // O(1)
{
    for (int i = 0; i < 26; i++)
    {
        if (feq1[i] != feq2[i])
        {
            return false;
        }
    }
    return true;
}

// Permutation in a String
bool checkInclusion(string s1, string s2) // Time: O(n), Space: O(1)
{
    int feq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        feq[s1[i] - 'a']++;
    }
    int winSize = s1.length();
    for (int i = 0; i < s2.length(); i++)
    {
        int winIdx = 0, idx = i;
        int winFeq[26] = {0};
        while (winSize > winIdx && idx < s2.length())
        {
            winFeq[s2[idx] - 'a']++;
            winIdx++;
            idx++;
        }
        if (isFreqSame(feq, winFeq))
        {
            return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}