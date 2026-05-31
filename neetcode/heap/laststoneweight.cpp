#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>

#include <util/timer.h>
using namespace std;


template<typename T>
class MaxHeap
{
    public:
    MaxHeap() {}

    void add(T val)
    {
        heap.emplace_back(val);
        
        int index = heap.size() - 1;
        int parent = -1;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent])
            {
                heapSwap(heap[index], heap[parent]);
                index = parent;
            }
            else   
                break;
        }
    }

    T pop()
    {
        if (heap.empty())
            return T{};
            
        if (heap.size() == 1)
        {   
            T popped = heap[0];
            heap.pop_back();
            return popped;
        }

        T popped = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return popped;
    }

    void heapify(int index)
    {
        while (index < heap.size())
        {
            int largest = index;
            int left = index * 2 + 1;
            int right = index * 2 + 2;

            if (left < heap.size() && heap[left] > heap[largest])
                largest = left;
            if (right < heap.size() && heap[right] > heap[largest])
                largest = right;
            
            if (largest == index)
                break;
            else
            {   
                heapSwap(heap[index], heap[largest]);
                index = largest;
            }
        }
    }

    T top()
    {
        return heap[0];
    }

    void heapSwap(T& l, T& r)
    {
        T temp = l;
        l = r;
        r = temp;
    }

    int size() { return heap.size(); }

private:
    std::vector<T> heap;
};

class Solution {
public:

    int lastStoneWeight(vector<int>& stones) 
    {
        MaxHeap<int> maxHeap;
        for (auto stone : stones)
            maxHeap.add(stone);

        while (maxHeap.size() > 1)
        {
            int y = maxHeap.pop();
            int x = maxHeap.pop();
            int diff = y - x;

            if (diff != 0)
                maxHeap.add(diff);
        }

        return maxHeap.size() == 0 ? 0 : maxHeap.pop();
    }
};

int main()
{
    std::vector<int> stones {10,4,2,10};
    Solution().lastStoneWeight(stones);
}