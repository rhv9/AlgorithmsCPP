#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        std::string building;
        std::vector<std::string> results;
        generateParentehsisInternal(n, building, 0, 0, results);
        return results;
    }

    void generateParentehsisInternal(int n, std::string& building, int open, int close, std::vector<std::string>& results)
    {
        if (open == n && close == n)
        {
            results.push_back(building);
            return;
        }
        if (open < n)
        {
            building.push_back('(');
            generateParentehsisInternal(n, building, open + 1, close, results);
            building.pop_back();
        }
        if (close < open && close < n)
        {
            building.push_back(')');
            generateParentehsisInternal(n, building, open, close + 1, results);
            building.pop_back();
        }
    }
};
