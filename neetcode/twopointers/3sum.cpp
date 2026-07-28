#include <util/timer.h>
using namespace std;

// brute force
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        std::vector<std::vector<int>> results;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            for (int j = i+1; j < nums.size() - 1; ++j)
            {
                for (int k = j+1; k < nums.size(); ++k)
                {
                    if ((nums[i] + nums[j] + nums[k]) == 0)
                        results.push_back({nums[i], nums[j], nums[k]});

                    while (k + 1 < nums.size() && nums[k] == nums[k+1])
                        ++k;
                }
                while (j + 1 < nums.size() && nums[j] == nums[j+1])
                    ++j;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i+1])
                ++i;
        }
        
        return results;
    }

};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        std::vector<std::vector<int>> results;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            // two sum
            int l = i + 1;
            int r = nums.size()-1;

            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum > 0)
                    --r;
                else if (sum < 0)
                    ++l;
                else
                {
                    results.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    while (l < r && nums[l] == nums[l-1])
                        ++l;
                }
                    
            }
        }
        
        return results;
    }

};
