#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {

        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][1] == newInterval[0])
            {
                // merge with interval i
            }
            if (newInterval[0] > intervals[i][1])
            {
                // not merging with interval i
                // need to count how many being merged forward from j
                int mergeIndex = i;
                for (int j = i + 1; j < intervals.size(); ++j)
                {
                    if (intervals[j][0] <= newInterval[1])
                        mergeIndex = j;
                    else 
                        break;
                }

                if (mergeIndex == i)
                {
                    intervals.insert(intervals.begin() + i + 1, newInterval);
                    return;
                }
                else
                {
                    // merging until interval mergeIndex
                }
            }

            return;
        }

        intervals.push_back(newInterval);
        return intervals;
    }
};
