#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[y].size(); ++x)
            {
                if (grid[y][x] == '1')
                {
                    dfs(grid, x, y);
                    ++islands;
                }
            }
        }
        return islands;
    }

    void dfs(std::vector<std::vector<char>>& grid, int x, int y)
    {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[y].size() || grid[y][x] == '0')
            return;
        
        grid[y][x] = '0';
        dfs(grid, x     , y + 1 );
        dfs(grid, x     , y - 1 );
        dfs(grid, x + 1 , y     );
        dfs(grid, x - 1 , y     );
    }
};

int main()
{
    std::vector<std::vector<char>> grid;
    grid.push_back(std::vector<char>{'1','1','0','0','1'});
    grid.push_back(std::vector<char>{'1','1','0','0','1'});
    grid.push_back(std::vector<char>{'0','0','1','0','0'});
    grid.push_back(std::vector<char>{'0','0','0','1','1'});

    std::cout << Solution().numIslands(grid) << std::endl;
}