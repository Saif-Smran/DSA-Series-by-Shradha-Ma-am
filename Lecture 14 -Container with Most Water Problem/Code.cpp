#include <iostream>
#include <vector>
using namespace std;

int maxAreaB(vector<int> &height) // Brute Force
{
    int maxWater = 0; // Ans

    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int w = j - i;
            int h = min(height[i], height[j]);
            int area = w * h;
            maxWater = max(maxWater, area);
        }
    }
    return maxWater;
}

int maxAreaOp(vector<int> &height) // Optimal 2 Pointer Approch
{
    int maxWater = 0; // Ans
    int lp = 0, rp = height.size() - 1;

    while (lp < rp)
    {
        int w = rp - lp;
        int h = min(height[lp], height[rp]);
        int area = w * h;
        maxWater = max(maxWater, area);
        (height[lp] < height[rp]) ? lp++ : rp--;
    }

    return maxWater;
}

int main()
{

    return 0;
}