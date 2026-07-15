#include <util/timer.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        std::unordered_map<int,int> cache;
        return changeInternal(amount, coins, cache);
    }

    int changeInternal(int amount, std::vector<int>& coins, std::unordered_map<int,int>& cache)
    {
        std::cout << amount << std::endl;
        if (amount == 0)
            return 1;

        if (amount < 0)
            return 0;

        if (cache.find(amount) != cache.end())
            return cache[amount];
            
        int count = 0;
        for (int coin : coins)
        {
            std::cout << "Coin: " << coin << std::endl;
            int added = coin;
            while (added <= amount)
            {
                count += changeInternal(amount - added, coins, cache);
                added += coin;
            }
        }

        cache[amount] = count;

        return count;
    }
};

int main()
{
    std::vector<int> nums = {2, 4};
    int amount = 7;

    std::cout << "Result " << Solution().change(amount, nums) << std::endl;
}