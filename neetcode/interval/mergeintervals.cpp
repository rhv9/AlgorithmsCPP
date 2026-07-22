#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& first, const std::vector<int>& second)
        {
            return first[0] < second[0];
        });

        std::vector<std::vector<int>> results;
        results.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= results.back()[1])
                results.back()[1] = std::max(intervals[i][1], results.back()[1]);
            else
                results.push_back(intervals[i]);
        }

        return results;
    }
};
