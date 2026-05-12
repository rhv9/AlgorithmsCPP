#include <iostream>
#include <vector>
#include <stdint.h>

#include <util/timer.h>

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if (minStack.size() <= 0)
            minStack.push_back(val);
        else if (val <= minStack[minStack.size() - 1])
            minStack.push_back(val);
    }
    
    void pop() {
        int topVal = top();
        if (topVal == minStack[minStack.size() - 1])
            minStack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        if (stack.size() <= 0)
            return INT32_MAX;
        return stack[stack.size()-1];
    }
    
    int getMin() {
        if (stack.size() <= 0)
            return INT32_MAX;
        return minStack[minStack.size() - 1];        
    }

    std::vector<int> stack;
    std::vector<int> minStack;
};


int main()
{
    MinStack minStack;

    {
        Timer timer;
        
        minStack.push(1);
        minStack.push(2);
        std::cout << minStack.top() << std::endl;
        minStack.pop();
        std::cout << minStack.top() << std::endl;

    }
}