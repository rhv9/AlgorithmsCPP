#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>

#include <util/timer.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
            return nullptr;
        std::unordered_map<int, Node*> visited;
        return cloneGraphDFS(node, visited);
    }

    Node* cloneGraphDFS(Node* node, std::unordered_map<int, Node*>& visited)
    {
        auto nodeIter = visited.find(node->val);
        if (nodeIter == visited.end())
        {
            Node* newNode = new Node(node->val);
            visited[node->val] = newNode;
            for (auto neighbourNode : node->neighbors)
                newNode->neighbors.push_back(cloneGraphDFS(neighbourNode, visited));

            return newNode;
        }
        return nodeIter->second;
    }
};



class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
            return nullptr;

        std::unordered_map<int, Node*> visited;
        std::queue<Node*> nodeQueue;
        
        nodeQueue.push(node);
        visited[node->val] = new Node(node->val);
        
        // breadth first solution
        while (!nodeQueue.empty())
        {
            Node* currentNode = nodeQueue.front();
            nodeQueue.pop();

            Node* copiedNode = visited[currentNode->val];
            for (auto neighbourNode : currentNode->neighbors)
            {
                auto neighbourIter = visited.find(neighbourNode->val);
                if (neighbourIter == visited.end())
                {
                    Node* newNeighbour = new Node(neighbourNode->val);
                    copiedNode->neighbors.push_back(newNeighbour);
                    visited[newNeighbour->val] = newNeighbour;
                    nodeQueue.emplace(neighbourNode);
                }
                else
                    copiedNode->neighbors.push_back(neighbourIter->second);
            }
        }
        return visited[node->val];
    }

};

