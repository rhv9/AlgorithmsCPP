#include <util/timer.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) 
    {
        int left = 0;
        int star = 0;

        for (char c : s)
        {
            if (c == '(')
                ++left;
            else if (c == ')')
                --left;
            else if (c == '*')
                ++star;

            if (left + star < 0)
                return false;
        }

        if (left == 0)
            return true;
        if (star >= left)
            return true;
        return false;
    }
};
