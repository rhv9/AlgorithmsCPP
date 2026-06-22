#include <util/timer.h>
using namespace std;

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        std::unordered_set<int> failedSet;
        return wordBreakCached(s, wordDict, 0, failedSet);
    }  

    bool wordBreakCached(std::string& s, std::vector<std::string>& wordDict, int offset, std::unordered_set<int>& failedSet)
    {
        if (offset == s.size())
            return true;
        if (failedSet.find(offset) != failedSet.end())
            return false;
        
        for (std::string& word : wordDict)
        {
            if (word.size() > s.size() - offset)
                continue;
            
            bool match = true;
            for (int i = 0; i < word.size(); ++i)
            {
                if (word[i] != s[offset + i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
                if (wordBreakCached(s, wordDict, offset + word.size(), failedSet))
                    return true;
        }

        failedSet.emplace(offset);
        return false;
    }
};
