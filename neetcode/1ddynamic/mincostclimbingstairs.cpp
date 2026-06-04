#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        std::vector<int> memoized;
        memoized.resize(cost.size());
        for (auto& elem : memoized)
            elem = -1;
        
        return std::min(minCostInternal(cost, memoized, 0), minCostInternal(cost, memoized, 1));
    }

    int minCostInternal(std::vector<int>& cost, std::vector<int>& memoized, int index)
    {
        if (index >= cost.size())
            return 0;
        
        if (memoized[index] != -1)
            return memoized[index];
        
        int oneStep = minCostInternal(cost, memoized, index + 1);
        int twoStep = minCostInternal(cost, memoized, index + 2);
        memoized[index] = std::min(oneStep, twoStep) + cost[index];

        return memoized[index];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        for (int i = cost.size() - 3; i >= 0; --i)
            cost[i] = cost[i] + std::min(cost[i + 1], cost[i + 2]);

        return std::min(cost[0], cost[1]);
    }
};

