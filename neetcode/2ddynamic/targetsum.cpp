#include <util/timer.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        std::unordered_map<uint64_t, int> cache;
        return findTargetRecursive(nums, target, 0, cache);
    }

    int findTargetRecursive(std::vector<int>& nums, int target, int offset, std::unordered_map<uint64_t, int>& cache)
    {
        if (offset == nums.size())
            return !target;

        union CacheKey
        {
            std::pair<int, int> targetOffset { 0, 0 };
            uint64_t hashValue;
        };
        CacheKey cacheKey;
        cacheKey.targetOffset = {target, offset};

        if (cache.find(cacheKey.hashValue) != cache.end())
            return cache[cacheKey.hashValue];
            
        int count = findTargetRecursive(nums, target - nums[offset], offset + 1, cache);
        count += findTargetRecursive(nums, target + nums[offset], offset + 1, cache);

        cache[cacheKey.hashValue] = count;
        return count;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int count = 0;
        std::unordered_map<int,int> dp;
        std::unordered_map<int,int> next_dp;
        std::unordered_map<int,int>* dp_ptr = &dp;
        std::unordered_map<int,int>* next_dp_ptr = &next_dp;
        dp[0] = 1;

        for (int num : nums)
        {
            for (auto[sum, count] : *dp_ptr)
            {
                (*next_dp_ptr)[sum + num] = next_dp_ptr->find(sum + num) == next_dp_ptr->end() ? count : (*next_dp_ptr)[sum + num] + count;
                (*next_dp_ptr)[sum - num] = next_dp_ptr->find(sum - num) == next_dp_ptr->end() ? count : (*next_dp_ptr)[sum - num] + count;
            }    
            dp_ptr->clear();
            std::swap(next_dp_ptr, dp_ptr);
        }
        return (*dp_ptr)[target];
    }

};

