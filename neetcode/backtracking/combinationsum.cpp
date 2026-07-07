#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        std::vector<std::vector<int>> results;
        std::vector<int> frequencies(nums.size(), 0);
        internalCombinationSum(nums, frequencies, 0, 0, target, results);
        return results;
    }

    void internalCombinationSum(std::vector<int>& nums, std::vector<int>& frequencies, int offset, int sumSoFar, int target,  std::vector<std::vector<int>>& results)
    {
        if (sumSoFar == target)
        {
            std::vector<int> combination;
            for (int i = 0; i < nums.size(); ++i)
                for (int j = 0; j < frequencies[i]; ++j)
                    combination.push_back(nums[i]);
            
            results.push_back(combination);
            return;
        }

        if (sumSoFar > target || offset >= nums.size())
            return;

        int addition = 0;
        while (addition + sumSoFar <= target)
        {
            internalCombinationSum(nums, frequencies, offset + 1, addition + sumSoFar, target, results);
            ++frequencies[offset];
            addition += nums[offset];
        }
        frequencies[offset] = 0;
    }
};
