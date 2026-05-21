#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        int height = matrix.size();
        int width = matrix[0].size();
        int left = 0, center = 0;
        int right = width * height - 1;

        while (left <= right)
        {
            center = left + (right - left) / 2;

            int x = center % width;
            int y = center / width;

            int val = matrix[y][x];

            if (val == target)
                return true;
            else if (target > val)
                left = center + 1;
            else if (target < val)
                right = center - 1;
        }

        return false;
    }
};


int main()
{

    {
        Timer timer;
        std::vector<int> nums {-1,0,2,4,6,8};
    }
}