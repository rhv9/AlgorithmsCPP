#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.size() == 0)
            return {};
        std::string tmpString = "";
        std::vector<std::string> results;
        letterCombiDFS(digits, 0, tmpString, results);
        return results;
    }

    void letterCombiDFS(const std::string& digits, int offset, std::string& tmpString, std::vector<std::string>& results)
    {
        static std::vector<std::string> mapping {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if (offset >= digits.size())
            results.push_back(tmpString);
        else
        {
            for (char c : mapping[digits[offset] - '0'])
            {
                tmpString.push_back(c);
                letterCombiDFS(digits, offset + 1, tmpString, results);
                tmpString.pop_back();
            }
        }
    }
};
