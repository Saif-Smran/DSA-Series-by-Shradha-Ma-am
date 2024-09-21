#include <iostream>
using namespace std;
#include <vector>

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int buy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > buy)
        {
            profit = max(profit, (prices[i] - buy));
        }
        buy = min(buy, prices[i]); // Update buy price
    }

    return profit;
}

int main()
{

    return 0;
}