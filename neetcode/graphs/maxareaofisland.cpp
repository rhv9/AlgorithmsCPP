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
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int maxFound = 0;

        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[y].size(); ++x)
            {
                struct Point 
                {
                    int x, y;
                };
                // found island
                if (grid[y][x] == 1)
                {
                    std::stack<Point> points;
                    points.emplace(x, y);
                    grid[y][x] = 2;
                    int islandArea = 0;
                    while (!points.empty())
                    {
                        Point p = points.top();
                        points.pop();
                        std::cout << p.x << "  " << p.y << "  " << islandArea << std::endl;
                        ++islandArea;   
                        grid[p.y][p.x] = 2;

                        if (p.x - 1 >= 0 && p.x - 1 < grid[0].size() && grid[p.y    ][p.x - 1] == 1)
                        {
                            grid[p.y][p.x - 1] = 2;
                            points.emplace(p.x - 1, p.y);
                        }
                        if (p.x + 1 >= 0 && p.x + 1 < grid[0].size() && grid[p.y    ][p.x + 1] == 1)
                        {
                            grid[p.y][p.x + 1] = 2;
                            points.emplace(p.x + 1, p.y);
                        }
                        if (p.y + 1 >= 0 && p.y + 1 < grid.size() && grid[p.y + 1][p.x    ] == 1)
                        {
                            grid[p.y + 1][p.x] = 2;
                            points.emplace(p.x, p.y + 1);
                        }
                        if (p.y - 1 >= 0 && p.y - 1 < grid.size() &&grid[p.y - 1][p.x    ] == 1)
                        {
                            grid[p.y + 1][p.x] = 2;
                            points.emplace(p.x, p.y - 1);
                        }
                    }
                    maxFound = std::max(islandArea, maxFound);
                }
            }
        }

        return maxFound;
    }
};