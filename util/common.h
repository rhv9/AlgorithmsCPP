#include <iostream>
#include <vector>
#include <chrono>

template <typename T>
void printVector(const std::vector<T>& vec)
{
    if (vec.size() == 0)
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";

    for (int i = 0; i < vec.size() - 1; ++i)
        std::cout << vec[i] << ", ";
    
    std::cout << vec[vec.size()-1] <<"]\n";
}