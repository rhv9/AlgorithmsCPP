#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;

        int center = 0;
        while (left <= right)
        {
            center = (right - left) / 2 + left;

            if (nums[center] == target)
                return center;
            else if (target > nums[center])
                left = center + 1;
            else if (target < nums[center])
                right = center - 1;
        }

        return -1;
    }
};

int main()
{

    {
        Timer timer;
        std::vector<int> nums {-1,0,2,4,6,8};
        Solution().search(nums, 4);
    }
}