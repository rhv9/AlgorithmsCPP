#include <util/timer.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        std::vector<int> cache(prices.size() * 2, -1);
        return maxProfit(prices, true, 0, cache);
    }

    int maxProfit(vector<int>& prices, bool buying, int offset, std::vector<int>& cache)
    {
        if (offset >= prices.size())
            return 0;

        if (cache[offset * 2 + buying] != -1)
            return cache[offset * 2 + buying];

        int newProfit = 0;

        if (buying)
            newProfit = maxProfit(prices, false, offset + 1, cache) - prices[offset];
        else
            newProfit = maxProfit(prices, true, offset + 2, cache) + prices[offset];    
        
        newProfit = std::max(newProfit, maxProfit(prices, buying, offset + 1, cache));

        cache[offset * 2 + buying] = newProfit;
        return newProfit;
    }
};