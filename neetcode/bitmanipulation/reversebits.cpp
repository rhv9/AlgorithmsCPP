#include <util/timer.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int reverse = 0;

        uint32_t offset = 2147483648;
        uint32_t otherOffset = 1;

        while (offset != 0)
        {
            if (n & otherOffset != 0)
                reverse = reverse | offset;
            offset >>= 1;
            otherOffset <<= otherOffset;
        }

        return reverse;
        
    }
};
