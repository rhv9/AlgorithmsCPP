#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int foundHash[10];
        for (auto& i : foundHash)
            i = 0;

        int valCheck = 1;
        // check row
        for (int y = 0; y < board.size(); ++y)
        {
            for (int x = 0; x < board[0].size(); ++x)
            {
                if (board[y][x] == '.')
                    continue;
                int val = board[y][x] - int('0');
                if (foundHash[val] == valCheck)
                    return false;
                foundHash[val] = valCheck;
            }
            ++valCheck;
        }

        // check column
        for (int x = 0; x < board[0].size(); ++x)
        {
            for (int y = 0; y < board.size(); ++y)
            {
                if (board[y][x] == '.')
                    continue;
                int val = board[y][x] - int('0');
                if (foundHash[val] == valCheck)
                    return false;
                foundHash[val] = valCheck;
            }
            ++valCheck;
        }

        // check each quadrant
        for (int yy = 0; yy < board.size() / 3; ++yy)
        {
            for (int xx = 0; xx < board[0].size() / 3; ++xx)
            {
                for (int y = yy * 3; y < 3 * (yy+1) ; ++y)
                {
                    for (int x = xx * 3; x < 3 * (xx+1); ++x)
                    {
                        if (board[y][x] == '.') 
                            continue;
                        int val = board[y][x] - int('0');
                        if (foundHash[val] == valCheck)
                            return false;
                        foundHash[val] = valCheck;
                    }
                }

                ++valCheck;
            }
        }
        
        return true;
    }
};


int main()
{

    {
        Timer timer;
    }
}