#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        std::stack<int> numStack;

        for (const std::string& token : tokens)
        {
            if (token.size() > 1)
                numStack.push(std::stoi(token));
            else if (token[0] == '+')
            {
                int second = numStack.top();
                numStack.pop();
                int first = numStack.top();
                numStack.pop();
                numStack.push(first + second);
            }
            else if (token[0] == '-')
            {
                int second = numStack.top();
                numStack.pop();
                int first = numStack.top();
                numStack.pop();
                numStack.push(first - second);
            }
            else if (token[0] == '*')
            {
                int second = numStack.top();
                numStack.pop();
                int first = numStack.top();
                numStack.pop();
                numStack.push(first * second);
            }
            else if (token[0] == '/')
            {
                int second = numStack.top();
                numStack.pop();
                int first = numStack.top();
                numStack.pop();
                numStack.push(first / second);
            }
            else
                numStack.push(std::stoi(token));
        }
        return numStack.top();
    }
};


int main()
{

    {
        Timer timer;
        std::vector<std::string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        int result = Solution().evalRPN(tokens);

        std::cout << result << std::endl;

    }
}