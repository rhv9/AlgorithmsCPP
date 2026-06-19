#include <util/timer.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if ((hand.size() % groupSize) != 0)
            return false;

        std::sort(hand.begin(), hand.end());

        int numOfHands = hand.size() / groupSize;
        std::vector<int> ends(numOfHands, -1);
        std::vector<int> sizes(numOfHands, 0);

        for (int card : hand)
        {
            bool foundPlace = false;
            for (int i = 0; i < numOfHands; ++i)
            {
                if (sizes[i] == 0 || sizes[i] != groupSize && card == ends[i] + 1)
                {
                    ends[i] = card;
                    ++sizes[i];
                    foundPlace = true;
                    break;
                }
            }

            if (!foundPlace)
                return false;
        }

        return true;
    }
};
