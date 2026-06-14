#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        std::unordered_map<int, int> solutions;
        return coinChangeInternal(coins, amount, solutions);
    }

    int coinChangeInternal(std::vector<int>& coins, int amount, std::unordered_map<int, int>& solutions)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (solutions.find(amount) != solutions.end())
            return solutions[amount];
        
        int min = -1;
        for (int elem : coins)
        {
            int count = coinChangeInternal(coins, amount - elem, solutions) + 1;
            if (count)
                min = min == -1 ? count : std::min(min, count);
        }

        solutions[amount] = min;
        return min;
    }
};
