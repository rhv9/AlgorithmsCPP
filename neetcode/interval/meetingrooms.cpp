#include <util/timer.h>
using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r)
        {
            return l.start > r.start;    
        });

        for (int i = 1; i < intervals.size() - 1; ++i)
        {
            if (intervals[i-1].end > intervals[i].start)
                return false;
        }
        
        return true;
    }
};
