#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        std::vector<std::vector<int>> results;
        std::vector<int> addedStack;
        std::sort(nums.begin(), nums.end());
        subsetsWithDupInternal(nums, results, addedStack, 0);
        return results;
    }

    void subsetsWithDupInternal(std::vector<int>& nums, std::vector<std::vector<int>>& results, std::vector<int>& addedStack, int offset)
    {
        if (offset >= nums.size())
        {
            results.push_back(addedStack);
            return;
        }

        addedStack.push_back(nums[offset]);
        subsetsWithDupInternal(nums, results, addedStack, offset + 1);
        addedStack.pop_back();

        while (offset + 1 < nums.size() && nums[offset] == nums[offset + 1])
            ++offset;
            
        subsetsWithDupInternal(nums, results, addedStack, offset + 1);
    }
};
