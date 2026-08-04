#include <util/timer.h>
using namespace std;

class Solution {
public:

    union HashValue
    {
        std::pair<int,int> amountOffset {0, 0};
        uint64_t key;
    };

    int change(int amount, vector<int>& coins) 
    {
        std::unordered_map<uint64_t,int> cache;
        return changeInternal(amount, coins, cache, 0);
    }

    int changeInternal(int amount, std::vector<int>& coins, std::unordered_map<uint64_t,int>& cache, int offset)
    {
        if (amount == 0)
            return 1;
        if (amount < 0 || offset == coins.size())
            return 0;

        HashValue hashVal;
        hashVal.amountOffset = {amount, offset};

        if (cache.find(hashVal.key) != cache.end())
            return cache[hashVal.key];

        int count = 0, added = 0;
        while (amount - added >= 0)
        {
            count += changeInternal(amount - added, coins, cache, offset + 1);
            added += coins[offset];
        }

        cache[hashVal.key] = count;

        return count;
    }
};

int main()
{
    std::vector<int> nums = {2, 4};
    int amount = 7;

    std::cout << "Result " << Solution().change(amount, nums) << std::endl;
}