#include <util/timer.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        std::vector<int> bestMoneys(nums.size(), 0);
        bestMoneys[nums.size()-1] = nums.back();
        int biggestMoney = 0;

        if (nums.size() >= 2)
        {
            bestMoneys[nums.size() - 2] = std::max(nums[nums.size() - 1], nums[nums.size() - 2]);
            biggestMoney = bestMoneys[nums.size() - 2];
        }
        else
            biggestMoney = nums.back();

        for (int i = nums.size()-3; i >= 0; --i)
        {
            bestMoneys[i] = std::max(nums[i] + bestMoneys[i + 2], bestMoneys[i+1]);
            biggestMoney = std::max(biggestMoney, bestMoneys[i]);
        }
        
        return biggestMoney;
    }
};


class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return nums[0];
        else
        {
            int neighbourOne = nums[nums.size() - 2];
            int neighbourTwo = nums[nums.size() - 1];

            for (int i = nums.size()-3; i >= 0; --i)
            {
                int current = std::max(nums[i] + neighbourTwo, neighbourOne);
                neighbourTwo = neighbourOne;
                neighbourOne = current;
            }
            return std::max(neighbourOne, neighbourTwo);
        }
    }
};

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int neighbourOne = 0;
        int neighbourTwo = 0;

        for (int num : nums)
        {
            int current = std::max(num + neighbourTwo, neighbourOne);
            neighbourTwo = neighbourOne;
            neighbourOne = current;
        }
        return neighbourOne;
    }
};


