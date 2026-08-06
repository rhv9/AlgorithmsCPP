#include <util/timer.h>
using namespace std;

class Solution {
public:
    void dfsTouch(vector<vector<char>>& board, const std::pair<int,int>& pos, char checkChar, char replaceChar)
    {
        std::vector<std::pair<int, int>> offsets = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto[xo, yo] : offsets)
        {
            auto[x, y] = pos;
            int xp = x + xo;
            int yp = y + yo;

            if (yp >= 0 && yp < board.size() && xp >= 0 && xp < board[0].size() && board[yp][xp] == checkChar)
            {
                board[yp][xp] = replaceChar;
                dfsTouch(board, {xp, yp}, checkChar, replaceChar);
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        std::queue<std::pair<int,int>> touchedSpots;

        for (int i = 0; i < board[0].size(); ++i)
        {
            if (board[0][i] == 'O')
            {
                board[0][i] = 'T';
                touchedSpots.push({i, 0});
                dfsTouch(board, {i, 0}, 'O', 'T');
            }

            if (board[board.size()-1][i] == 'O')
            {
                board[board.size()-1][i] = 'T';
                touchedSpots.push({i, board.size()-1});
                dfsTouch(board, {i, board.size()-1}, 'O', 'T');
            }
        }

        for (int i = 0; i < board.size(); ++i)
        {
            if (board[i][0] == 'O')
            {
                board[i][0] = 'T';
                touchedSpots.push({0, i});
                dfsTouch(board, {0, i}, 'O', 'T');
            }

            if (board[i][board[0].size()-1] == 'O')
            {
                board[i][board[0].size()-1] = 'T';
                touchedSpots.push({board[0].size()-1, i});
                dfsTouch(board, {board[0].size()-1, i}, 'O', 'T');
            }
        }

        for (int y = 1; y < board.size() - 1; ++y)
            for (int x = 1; x < board[y].size() - 1; ++x)
                if (board[y][x] == 'O')
                    board[y][x] = 'X';

        while (!touchedSpots.empty())
        {
            auto coord = touchedSpots.front();
            touchedSpots.pop();
            board[coord.second][coord.first] = 'O';
            dfsTouch(board, coord, 'T', 'O');
        }
    }
};
