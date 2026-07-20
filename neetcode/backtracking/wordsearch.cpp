#include <util/timer.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        for (int y = 0; y < board.size(); ++y)
            for (int x = 0; x < board[y].size(); ++x)
                if (existsRecursive(board, word, 0, {x, y}))
                    return true;

        return false;
    }

    bool existsRecursive(std::vector<std::vector<char>>& board, std::string& word, int offset, std::pair<int,int> pos)
    {
        static std::pair<int,int> positionOffsets[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        if (offset == word.size())
            return true;

        auto[x, y] = pos;
        
        if (y < 0 || y >= board.size() || x < 0 || x >= board[y].size() || board[y][x] != word.at(offset))
            return false;
        
        char oldChar = board[y][x];
        board[y][x] = '!';

        for (auto[xo, yo] : positionOffsets)
            if (existsRecursive(board, word, offset + 1, {x + xo, y + yo}))
                return true;

        board[y][x] = oldChar;

        return false;
    }
};
