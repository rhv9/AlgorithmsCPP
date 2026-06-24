#include <util/timer.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        std::vector<int> cache(nums.size(), 1);
        
        int longestSubsequence = 1;
        for (int i = nums.size() - 2; i >= 0; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] < nums[j])
                {
                    cache[i] = std::max(cache[i], cache[j] + 1);
                    longestSubsequence = std::max(longestSubsequence, cache[i]);
                }
            }
        }

        return longestSubsequence;
    }
};
