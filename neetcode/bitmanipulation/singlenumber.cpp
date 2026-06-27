#include <util/timer.h>
using namespace std;
#include <numeric>

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        return std::reduce(nums.begin(), nums.end(), 0, [](int first, int second) { return first ^ second;});
    }
};
