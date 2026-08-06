#include <util/timer.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        std::vector<int> charMap(70, 0);
        std::vector<int> charMapDuplicate(70, 0);
        for (char c : t)
        {
            charMap[c - 'A']++;
            charMapDuplicate[c - 'A']++;
        }

        int size = t.size();
        int left = 0, right = 0;
        int currentSize = 0;
        bool minLeft = 0, minRight = 0;
        for (right = 0; right < s.size(); ++right)
        {
            char c = s[right];
            if (charMap[c - 'A'] > 0)
            {
                if (size == 0)
                {

                }

                --size;
                --charMap[c - 'A'];
                if (currentSize == 0)
                {
                    ++currentSize;
                    left = right;
                }

                if ()
            }
        }

    }
};
