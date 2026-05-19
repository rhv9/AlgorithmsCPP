#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        std::vector<int> results;
        results.reserve(nums.size());

        int product = 1;
        int zeroPos = -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                // all values must be zero
                if (zeroPos != -1)
                    return results;

                for (int i = 0; i < nums.size(); ++i)
                    results.push_back(0);
                zeroPos = i;
            }
            else 
                product *= nums[i];
        }

        if (zeroPos != -1)
        {
            results[zeroPos] = product * nums[0];
            return results;
        }

        results.push_back(product);

        for (int i = 1; i < nums.size(); ++i)
        {
            product = product / nums[i];
            product = product * nums[i-1];
            results.push_back(product);
        }

        return results;
    }
};


int main()
{

    {
        Timer timer;
        std::vector<int> nums {-1,0,1,2,3};
        std::vector<int> results = Solution().productExceptSelf(nums);

        for (auto i : results)
            std::cout << i << std::endl;
    }
}