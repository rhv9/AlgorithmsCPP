#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>

#include <util/timer.h>
using namespace std;

template<typename T>
class MinHeap
{
public:
    MinHeap() {}

    void add(T val)
    {
        heap.emplace_back(val);

        int index = heap.size() - 1;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent])
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

        T res = heap[0];
        if (heap.size() == 1)
        {
            heap.pop_back();
            return res;
        }

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        
        return res;
    }

    void heapify(int index)
    {
        while (index < heap.size())
        {
            int smallest = index;

            int left = index * 2 + 1;
            int right = index * 2 + 2;
            
            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;
            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;
            
            if (smallest == index)
                break;
            else
            {
                heapSwap(heap[smallest], heap[index]);
                index = smallest;
            }
        }
    }
    void heapSwap(T& l, T& r)
    {
        T temp = l;
        l = r;
        r = temp;
    }

    int size() const { return heap.size(); }
    bool empty() const { return size() == 0;}

    std::vector<T> heap;
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        struct Point
        {
            int index;
            float squareDistance;

            bool operator<(const Point& other) const
            {
                return squareDistance < other.squareDistance;
            }
        };

        MinHeap<Point> minHeap;

        for (int i = 0; i < points.size(); ++i)
        {
            int x = points[i][0];
            int y = points[i][1];
            int squareDistance = x * x + y * y;
            Point p;
            p.index = i;
            p.squareDistance = squareDistance;

            minHeap.add(p);
        }

        int resultIndex = 0;
        std::vector<std::vector<int>> results;
        while (k > 0)
        {
            results.emplace_back(points[minHeap.pop().index]);
            --k;
        }

        return results;
    }
};
