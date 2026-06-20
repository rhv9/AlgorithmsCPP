#include <util/timer.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int l = 0;
        int gasSurplus = 0;
        int sum = 0;

        for (int r = 0; r < gas.size(); ++r)
        {
            int diff = gas[r] - cost[r];
            sum += diff;
            gasSurplus += diff;

            if (gasSurplus < 0)
            {
                l = r + 1;
                gasSurplus = 0;
            }
        }

        return sum < 0 ? -1 : l;
    }
};
