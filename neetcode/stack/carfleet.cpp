#include <util/timer.h>
using namespace std;
#include <numeric>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        std::vector<int> indices;
        indices.resize(position.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&position](int l, int r) { return position[l] < position[r];});
        std::vector<float> times;

        for (int i = position.size() -1; i >= 0; --i)
        {
            float time = ((float)target - position[indices[i]]) / (float)speed[indices[i]];
            times.push_back(time);
            if (times.size() >= 2 && times[times.size() - 1] <= times[times.size() - 2])
                times.pop_back();
        }
        return times.size();
    }
};
