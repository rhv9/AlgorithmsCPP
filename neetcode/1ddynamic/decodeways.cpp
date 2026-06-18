#include <util/timer.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) 
    {
        if (s[0] == '0')
            return 0;
        std::vector<int> decodeWays(s.size(), -1);
        return numDecodingsIndex(s, 0, decodeWays);
    }

    int numDecodingsIndex(std::string& s, int index, std::vector<int>& decodeWays)
    {
        static std::string twoDigit = "00";

        if (index >= s.size() - 1)
            return 1;

        if (s[index] == '0')
            return 0;

        if (decodeWays[index] != -1)
            return decodeWays[index];

        twoDigit[0] = s[index];
        twoDigit[1] = s[index + 1];

        int ways = 0;
        int num = std::stoi(twoDigit);

        if (num == 10 || num == 20)
        {
            ways = numDecodingsIndex(s, index + 2, decodeWays);
        }
        else if (num <= 26)
            ways = numDecodingsIndex(s, index + 1, decodeWays) + numDecodingsIndex(s, index + 2, decodeWays);
        else
            ways = numDecodingsIndex(s, index + 1, decodeWays);

        decodeWays[index] = ways;
        return ways;
    }
};
