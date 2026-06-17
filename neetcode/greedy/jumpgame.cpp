#include <util/timer.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        std::vector<int> canJumpMemory(nums.size(), -1);
        return jumpRecursive(nums, canJumpMemory, 0);
    }

    bool jumpRecursive(vector<int>& nums, std::vector<int>& canJumpMemory, int index)
    {
        if (index >= nums.size() - 1)
            return true;
        
        if (canJumpMemory[index] != -1)
            return canJumpMemory[index];

        if (nums[index] == 0)
            return false;
        
        for (int i = nums[index]; i > 0; --i)
            if (jumpRecursive(nums, canJumpMemory, i + index))
                return true;

        return canJumpMemory[index] = false;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) 
    {
        return jumpRecursive(nums, 0);
    }

    bool jumpRecursive(vector<int>& nums, int index)
    {
        if (index >= nums.size() - 1)
            return true;
        if (nums[index] == 0)
            return false;
        
        for (int i = nums[index]; i > 0; --i)
            if (jumpRecursive(nums, i + index))
                return true;

        return nums[index] = 0;
    }
};

class Solution3 {
public:
    bool canJump(vector<int>& nums) 
    {
        int index = 0;
        std::stack<int> indices;
        while (index < nums.size() - 1)
        {
            if (nums[index] == 0)
            {
                if (index == 0)
                    break;

                index = indices.top();
                indices.pop();
                --nums[index];
                continue;
            }
            else
            {
                indices.push(index);
                index += nums[index];
            }
        }
        return index >= nums.size() - 1;
    }
};

class Solution4 {
public:
    bool canJump(vector<int>& nums) 
    {
        int index = 0;
        int maxReachable = 0;

        while (index <= maxReachable)
        {
            if (maxReachable >= nums.size() - 1)
                return true;
            maxReachable = std::max(maxReachable, nums[index] + index);
            index++;
        }

        return false;
    }
};



int main()
{
    std::vector<int> nums = {1,2,0,1,0};
    std::cout << (Solution3().canJump(nums) ? "true" : "false") << std::endl;
}