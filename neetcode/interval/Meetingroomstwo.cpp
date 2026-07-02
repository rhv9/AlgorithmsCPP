#include <util/timer.h>
using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
}

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        std::vector<int> startTimes, endTimes;
        for (const Interval& elem : intervals)
        {
            startTimes.push_back(elem.start);
            endTimes.push_back(elem.end);
        }

        std::sort(startTimes.begin(), startTimes.end());
        std::sort(endTimes.begin(), endTimes.end());

        int count = 0, maxCount = 0;
        int s = 0, e = 0;
        while (s < startTimes.size())
        {
            if (startTimes[s] < endTimes[e])
            {
                ++count;
                maxCount = std::max(count, maxCount);
                ++s;
            }
            else
            {
                --count;
                ++e;
            }
        }

        return maxCount;
    }
};
www
