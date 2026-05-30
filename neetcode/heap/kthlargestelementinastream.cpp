#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>

#include <util/timer.h>
using namespace std;

class KthLargest {
public:

    std::vector<int> heapNums;
    int maxSize = 0;

    KthLargest(int k, vector<int>& nums) 
    {
        maxSize = k;
        for (auto& elem : nums)
            add(elem);
    }

    int add(int val) 
    {
        addToHeap(val);
        if (heapNums.size() > maxSize)
            popHeap();
        return heapNums[0];    
    }
    

    void heapSwap(int& l, int& r)
    {
        int temp = l;
        l = r;
        r = temp;
    }

    void addToHeap(int num)
    {
        heapNums.push_back(num);

        int index = heapNums.size() - 1;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heapNums[index] < heapNums[parent])
            {
                // swap
                heapSwap(heapNums[index], heapNums[parent]);
                index = parent;
            }
            else
                break;

        }
    }

    void popHeap()
    {
        heapSwap(heapNums[0], heapNums[heapNums.size() - 1]);
        heapNums.pop_back();
        int index = 0;
        while (index < heapNums.size())
        {
            int smallest = index;
            
            int leftChild = index * 2 + 1;
            int rightChild = index * 2 + 2;
            
            if (leftChild < heapNums.size() && heapNums[leftChild] < heapNums[smallest])
                smallest = leftChild;
            if (rightChild < heapNums.size() && heapNums[rightChild] < heapNums[smallest])
                smallest = rightChild;
            
            if (smallest == index)
                break;
            else
            {
                heapSwap(heapNums[index], heapNums[smallest]);
                index = smallest;
            }
        }
    }
};

int main()
{
    std::vector<int> nums{0};
    KthLargest sol(4, nums);

    sol.add(2);
    sol.add(3);
    sol.add(4);
    sol.add(1);

    sol.popHeap();
}
