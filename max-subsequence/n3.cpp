#include <iostream>
#include <vector>
#include "../util/timer.h"

int maxSubSequenceN3(const std::vector<int>& input)
{
    int maxSum = 0;

    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = i; j < input.size(); ++j)
        {
            
            int sum = 0;
            for (int k = i; k <= j; ++k)
                sum += input[k];

            if (sum > maxSum)
                maxSum = sum;
        }
    }

    return maxSum;

}

int main()
{

    std::vector<int> input {0, 2, -1, 5, -2, -1, 4, 6, 1, -2};
    int result = 0;
    {
        Timer timer;
        result = maxSubSequenceN3(input);
    
    }
    std::cout << "Hello World!" << std::endl;
    std::cout << result << std::endl;
}