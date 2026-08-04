#include <util/timer.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        std::vector<std::vector<std::pair<bool, bool>>> oceanReaches(heights.size(), std::vector<std::pair<bool,bool>>(heights[0].size(), std::pair<bool, bool>{false, false}));
        
        // set pacific
        std::queue<std::pair<int,int>> pacificQueue, atlanticQueue;
        for (int i = 0; i < heights[0].size(); ++i)
        {
            oceanReaches[0][i].first = true;
            pacificQueue.push({i, 0});
        }
        for (int i = 0; i < heights.size(); ++i)
        {
            oceanReaches[i][0].first = true;
            pacificQueue.push({0, i});
        }

        // set atlantic
        for (int i = 0; i < heights[0].size(); ++i)
        {
            oceanReaches[oceanReaches.size() - 1][i].second = true;
            atlanticQueue.push({i, oceanReaches.size() - 1});
        }
        for (int i = 0; i < heights.size(); ++i)
        {
            oceanReaches[i][oceanReaches[i].size() - 1].second = true;
            atlanticQueue.push({oceanReaches[i].size() - 1, i});
        }

        std::vector<std::pair<int,int>> offsets = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!pacificQueue.empty())
        {
            auto[x, y] = pacificQueue.front();
            pacificQueue.pop();
            for (auto[xo, yo] : offsets)
            {
                int xp = xo + x;
                int yp = yo + y;
                if (yp >= 0 && yp < oceanReaches.size() && xp >= 0 && xp < oceanReaches[yp].size() && heights[yp][xp] >= heights[y][x] && !oceanReaches[yp][xp].first)
                {
                    oceanReaches[yp][xp].first = true;
                    pacificQueue.push({xp, yp});
                }
            }
        }

        while (!atlanticQueue.empty())
        {
            auto[x, y] = atlanticQueue.front();
            atlanticQueue.pop();
            for (auto[xo, yo] : offsets)
            {
                int xp = xo + x;
                int yp = yo + y;
                if (yp >= 0 && yp < oceanReaches.size() && xp >= 0 && xp < oceanReaches[yp].size() && heights[yp][xp] >= heights[y][x] && !oceanReaches[yp][xp].second)
                {
                    oceanReaches[yp][xp].second = true;
                    atlanticQueue.push({xp, yp});
                }
            }
        }

        std::vector<std::vector<int>> results;
        for (int y = 0; y < oceanReaches.size(); ++y)
        {
            for (int x = 0; x < oceanReaches[y].size(); ++x)
            {
                if (oceanReaches[y][x].first && oceanReaches[y][x].second)
                    results.push_back({y, x});
            }
        }
        return results;
    }
};
