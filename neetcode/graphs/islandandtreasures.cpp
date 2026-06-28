#include <util/timer.h>
using namespace std;

class Solution {
public:
    const int WATER = -1;
    const int TREASURE = 0;
    const int LAND = 2147483647; 

    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        std::queue<std::pair<int,int>> toVisit;

        for (int y = 0; y < grid.size(); ++y)
            for (int x = 0; x < grid[y].size(); ++x)
                if (grid[y][x] == TREASURE)
                    toVisit.push({x, y});

        std::vector<std::pair<int,int>> offsets = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int distance  = 1;
        while (!toVisit.empty())
        {
            int length = toVisit.size();
            for (int i = 0; i < length; ++i)
            {
                auto[x, y] = toVisit.front();
                toVisit.pop();
                
                for (auto[xOffset, yOffset] : offsets)
                {
                    int xp = x + xOffset;
                    int yp = y + yOffset;
    
                    if (yp < 0 || yp >= grid.size() || xp < 0 || xp >= grid[yp].size() || grid[yp][xp] != LAND)
                        continue;

                    grid[yp][xp] = distance;
                    toVisit.emplace(xp, yp);
                }
            }
            ++distance;
        }
    }

};

