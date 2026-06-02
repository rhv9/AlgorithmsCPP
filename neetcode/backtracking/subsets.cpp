#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector<std::vector<int>> results;
        std::vector<int> subsetContainer;
        subsetContainer.reserve(nums.size());
        allSubsets(nums, 0, subsetContainer, results);
        return results;
    }

    void allSubsets(std::vector<int>& nums, int index, std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        if (index >= nums.size())
        {
            results.push_back(subset);
            return;
        }        

        allSubsets(nums, index + 1, subset, results);
        subset.push_back(nums[index]);
        allSubsets(nums, index + 1, subset, results);
        subset.pop_back();
    }
};
