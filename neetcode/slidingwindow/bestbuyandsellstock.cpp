#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>

#include <util/timer.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int biggestProfit = 0;

        int lowestBuy = 1000000;

        for (int price : prices)
        {
            if (price <= lowestBuy)
                lowestBuy = price;
            else 
            {
                int profit = price - lowestBuy;
                biggestProfit = (profit > biggestProfit) ? profit : biggestProfit;
            }
        }

        return biggestProfit;
    }
};



int main()
{

    {
        Timer timer;
        std::vector<std::string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};


    }
}