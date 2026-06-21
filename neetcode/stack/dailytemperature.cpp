#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        std::stack<std::pair<int, int>> descTempStack;
        std::vector<int> results(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            while (!descTempStack.empty())
            {
                if (temperatures[i] < descTempStack.top().first)
                {
                    results[i] = descTempStack.top().second - i;
                    descTempStack.push({temperatures[i], i});
                    break;
                }
                descTempStack.pop();
            }
            if (descTempStack.empty())
            {
                descTempStack.push({temperatures[i], i});
                results[i] = 0;
            }
        }
        return results;
    }
};
