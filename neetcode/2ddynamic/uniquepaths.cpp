#include <util/timer.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<int> cache(m * n, 1);

        for (int y = m - 2; y >= 0; --y)
            for (int x = n - 2; x >= 0; --x)
                cache[y * n + x] = cache[(y+1) * n + x] + cache[y * n + x + 1];

        return cache[0];
    }

};

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<int> cache(n * 2, 1);
        int firstYOffset = 0, secondYOffset = n;
        
        for (int y = m - 2; y >= 0; --y)
        {
            for (int x = n - 2; x >= 0; --x)
                cache[firstYOffset + x] = cache[secondYOffset + x] + cache[firstYOffset + x + 1];
            std::swap(firstYOffset, secondYOffset);
        }
        return cache[secondYOffset];
    }

};