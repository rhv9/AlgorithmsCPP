#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int foundChars[256];
        for (int& elem : foundChars)
            elem = -1;
        
        int longestFound = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s.at(i); 
            if (foundChars[c] == -1)
            {
                foundChars[c] = i;
                longestFound = std::max(longestFound, i + 1 - left);
            }
            else 
            {
                int prevLeft = left;
                left = foundChars[c] + 1;

                // remove characters up to oldpos
                for (int j = prevLeft; j < left - 1; ++j)
                    foundChars[s.at(j)] = -1;

                foundChars[c] = i;
                longestFound = std::max(longestFound, i + 1 - left);
            }
        }
        return longestFound;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        
        int foundChars[256];
        for (int& elem : foundChars)
            elem = -1;
        
        int longestFound = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s.at(i); 
            if (foundChars[c] == -1)
                foundChars[c] = i;
            else 
            {
                while (foundChars[c] != -1)
                    foundChars[s.at(left++)] = -1;
                foundChars[c] = i;
            }
            longestFound = std::max(longestFound, i + 1 - left);
        }
        return longestFound;
    }
};


int main()
{
    {
        Timer timer;
    }
}