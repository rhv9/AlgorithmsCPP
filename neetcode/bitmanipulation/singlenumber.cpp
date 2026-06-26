#include <util/timer.h>
using namespace std;
#include <numeric>

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int xorResult = 0;
        for (int num : nums)
            xorResult = xorResult ^ num;
        int xorResult = std::reduce(nums.begin(), nums.end(), 0, [](int first, int second) { return first ^ second;});
        return xorResult;
    }
};
