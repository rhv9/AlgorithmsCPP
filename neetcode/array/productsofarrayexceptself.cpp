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

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        std::vector<int> results;
        results.reserve(nums.size());

        std::vector<int> prefix;
        prefix.reserve(nums.size());

        std::vector<int> suffix;
        suffix.reserve(nums.size());

        prefix[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        suffix[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0 ; --i)
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for (int i = 0; i < nums.size(); ++i)
            results.push_back(prefix[i] * suffix[i]);

        return results;
    }
};


class Solution3 {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        std::vector<int> results;
        results.reserve(nums.size());

        results.push_back(1);
        
        for (int i = 1; i < nums.size(); ++i)
            results.push_back(results[i-1] * nums[i-1]);

        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            results[i] = results[i] * suffix;
            suffix = suffix * nums[i];
        }
        return results;
    }
};


int main()
{

    {
        Timer timer;
        std::vector<int> nums {-1,0,1,2,3};
        std::vector<int> results = Solution3().productExceptSelf(nums);

        for (auto i : results)
            std::cout << i << std::endl;
    }
}