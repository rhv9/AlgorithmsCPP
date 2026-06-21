#pragma once
#include "common.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


class Timer
{
public:
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        auto now = std::chrono::high_resolution_clock::now();

        std::cout << "Timer: " << std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count() << " ms" << std::endl;
        std::cout << "Timer: " << std::chrono::duration_cast<std::chrono::microseconds>(now - start).count() << " microseconds" << std::endl;
        std::cout << "Timer: " << std::chrono::duration_cast<std::chrono::nanoseconds>(now - start).count() << " nanoseconds" << std::endl;
    
    }
    
private:
    std::chrono::_V2::system_clock::time_point start;
};