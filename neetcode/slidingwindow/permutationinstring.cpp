#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>
#include <array>

#include <util/timer.h>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        constexpr int hashSize = 'z' - 'a' + 1;
        std::array<int, hashSize> hashMap;

        for (auto& elem : hashMap)
            elem = 0;
        for (char c : s1)
            ++hashMap[c - 'a'];

        int left = 0, right = 0;
        while (right < s2.size())
        {
            if (hashMap[s2.at(right) - 'a'] != 0)
                --hashMap[s2.at(right++) - 'a'];
            else if (left != right)
                ++hashMap[s2.at(left++) - 'a'];
            else
                left = ++right;
                
            if ((right - left) == s1.size())
                    return true;
        }
        return false;
    }
};
