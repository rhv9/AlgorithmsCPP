#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        std::unordered_set<char> uniqueChars;
        
        for (char c : s)
            if (uniqueChars.count(c) == 0) uniqueChars.insert(c);

        int longest = 0;
        for (char c : uniqueChars)
        {
            int left = 0;
            int right = 0;
            std::queue<int> replaceIndices;
            while (right < s.length())
            {
                if (s.at(right) == c)
                    ++right;
                else
                {
                    // we have replacements
                    if (k == 0)
                    {
                        left = ++right;
                        continue;
                    }
                    else if (replaceIndices.size() == k)
                    {
                        // not enough replacements
                        // remove earliest replacement
                        int earliestReplaceIndex = replaceIndices.front();
                        left = earliestReplaceIndex + 1;
                        
                        replaceIndices.pop();
                    }
                    // add new replacement
                    replaceIndices.push(right);
                    ++right;
                }
                longest = std::max(longest, right - left);
            }
        }
        return longest;
    }
};
