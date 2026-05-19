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

        for (int i = 1; i < nums.size(); ++i)
            product *= nums[i];

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