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
    int climbStairs(int n) 
    {
        std::vector<int> cache;
        cache.resize(n);
        for (auto& elem : cache)
            elem = -1;
        return memoizedClimbStairs(cache, 0, n);
    }

    int memoizedClimbStairs(std::vector<int>& cache, int step, int n)
    {
        if (step > n)
            return 0;
        if (step == n)
            return 1;

        if (cache[step] != -1)
            return cache[step];

        int one = memoizedClimbStairs(cache, step + 1, n);
        int two = memoizedClimbStairs(cache, step + 2, n);

        cache[step] = one + two;
        return one + two;
    }
};
