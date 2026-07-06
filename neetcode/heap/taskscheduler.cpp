#include <util/timer.h>
#include <array>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        std::array<int, 26> letterCounts;
        letterCounts.fill(0);
        for (char c : tasks)
            ++letterCounts[c - 'A'];
            
        auto compare = [&letterCounts](const int& l, const int& r) { return letterCounts[l] < letterCounts[r];};
        std::priority_queue<int, std::vector<int>, decltype(compare)> maxHeap(compare); 

        for (int i = 0; i < letterCounts.size(); ++i)
            if (letterCounts[i] != 0)
                maxHeap.emplace(i);

        struct CooldownElement
        {
            int letter;
            int timeAdded;
        };
        std::queue<CooldownElement> cooldownList;

        int cycles = 0;

        while (!maxHeap.empty() || !cooldownList.empty())
        {
            if (!cooldownList.empty() && cycles > (cooldownList.front().timeAdded + n))
            {
                maxHeap.push(cooldownList.front().letter);
                cooldownList.pop();
            }

            if (!maxHeap.empty())
            {
                int letterFound = maxHeap.top();
                maxHeap.pop();

                if (--letterCounts[letterFound] > 0)
                    cooldownList.emplace(letterFound, cycles);
            }

            cycles++;
        }

        return cycles;
    }
};
