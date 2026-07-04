#include <util/timer.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        struct GraphEdge
        {
            int targetNode;
            int weight;
        };
        std::vector<std::vector<GraphEdge>> directedGraph(n);

        for (std::vector<int>& link : times)
            directedGraph[link[0]-1].emplace_back(link[1]-1, link[2]);

        std::vector<bool> visitedNodes(n, false);
        int reachedNodesCount = 0, timeTaken = 0;

        auto compare = [](const GraphEdge& l, const GraphEdge& r) { return l.weight > r.weight; };
        std::priority_queue<GraphEdge, std::vector<GraphEdge>, decltype(compare)> minHeap(compare);

        minHeap.emplace(k-1, 0);

        while (!minHeap.empty())
        {
            GraphEdge edge = minHeap.top();
            minHeap.pop();

            if (!visitedNodes[edge.targetNode])
            {
                visitedNodes[edge.targetNode] = true;
                timeTaken += edge.weight;
                ++reachedNodesCount;

                if (reachedNodesCount == n)
                    break;
                
                if (minHeap.size() != 0)
                {
                    GraphEdge* base = (GraphEdge*)&minHeap.top();
                    for (int i = 0; i < minHeap.size(); ++i)
                        base[i].weight -= edge.weight;
                }

                for (GraphEdge& eachEdge : directedGraph[edge.targetNode])
                    minHeap.push(eachEdge);
                
            }
        }

        return reachedNodesCount == n ? timeTaken : -1;
    }
};

int main()
{
    std::vector<std::vector<int>> testCase = {{1,2,1},{2,3,1}};

    std::cout << "Result: " << Solution().networkDelayTime(testCase, 3, 2) << std::endl;
}