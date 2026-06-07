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
            int left = 0, right = 0, replacedCount = 0;
            while (right < s.length())
            {
                if (s.at(right) == c)
                    ++right;
                else
                {
                    if (replacedCount < k)
                        ++replacedCount;
                    else
                    {
                        while (s.at(left) == c)
                            ++left;
                        ++left;
                    }
                    ++right;
                }
                longest = std::max(longest, right - left);
            }
        }
        return longest;
    }
};
