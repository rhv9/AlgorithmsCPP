#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int lastIndices[26];
        for (int i = 0; i < s.size(); ++i)
            lastIndices[s.at(i) - 'a'] = i;

        std::vector<int> results;
        int counter = 0, right = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            ++counter;
            right = std::max(lastIndices[s.at(i) - 'a'], right);
            if (i ==  right)
            {
                results.push_back(counter);
                counter = 0;
            }
        }
        return results;
    }
};

int main()
{
    std::string s = "xyxxyzbzbbisl";
    Solution().partitionLabels(s);
}
