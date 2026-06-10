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
    vector<vector<int>> permute(vector<int>& nums) 
    {
        std::vector<std::vector<int>> permutations;
        permuteIntenral(nums, 0, permutations);
        return permutations;
    }

    void permuteIntenral(std::vector<int>& nums, int index, std::vector<std::vector<int>>& permutations)
    {
        if (index >= nums.size())
        {
            permutations.push_back(nums);
            return;
        }        

        permuteIntenral(nums, index + 1, permutations);
        for (int i = index + 1; i < nums.size(); ++i)
        {
            std::swap(nums[index], nums[i]);
            permuteIntenral(nums, index + 1, permutations);
            std::swap(nums[index], nums[i]);
        }
    }
};
