#include <util/timer.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        constexpr int EMPTY = 0;
        constexpr int FRESH = 1;
        constexpr int ROTTEN = 2;
        constexpr int SOON_ROTTING = 3;

        std::pair<int,int> offsets[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        std::queue<std::pair<int,int>> soonRottingQueue;
        int freshCount = 0;

        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[y].size(); ++x)
            {
                freshCount += (grid[y][x] == FRESH || grid[y][x] == SOON_ROTTING); 

                if (grid[y][x] == ROTTEN)
                {
                    for (auto[xo, yo] : offsets)
                    {
                        int xp = x + xo;
                        int yp = y + yo;

                        if (yp < 0 || yp >= grid.size() || xp < 0 || xp >= grid[yp].size())
                            continue;
                        
                        if (grid[yp][xp] == FRESH)
                        {
                            grid[yp][xp] = SOON_ROTTING;
                            soonRottingQueue.emplace(xp, yp);
                        }
                    }
                }
            }
        }
        int minutes = 0;
        while (!soonRottingQueue.empty())
        {
            ++minutes;
            int size = soonRottingQueue.size();

            for (int i = 0; i < size; ++i)
            {
                auto[x, y] = soonRottingQueue.front();
                soonRottingQueue.pop();

                if (grid[y][x] == SOON_ROTTING)
                {
                    grid[y][x] = ROTTEN;
                    --freshCount;

                    for (auto[xo, yo] : offsets)
                    {
                        int xp = x + xo;
                        int yp = y + yo;

                        if (yp < 0 || yp >= grid.size() || xp < 0 || xp >= grid[yp].size())
                            continue;

                        if (grid[yp][xp] == FRESH)
                        {
                            grid[yp][xp] = SOON_ROTTING;
                            soonRottingQueue.emplace(xp, yp);
                        }
                    }

                }
            }
        }

        return freshCount == 0 ? minutes : -1;        
    }
};
