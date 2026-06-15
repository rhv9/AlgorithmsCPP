#include <util/timer.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int curMax = nums[0];
        int curSubArray = -100000;
        for (int num : nums)
        {
            curSubArray = std::max(curSubArray + num, num);
            curMax = std::max(curMax, curSubArray);
        }
        return curMax;
    }
};
