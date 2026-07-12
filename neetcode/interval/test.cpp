#include <util/timer.h>
using namespace std;


int main()
{
    std::vector<int> test = {0, 1, 2, 3};

    test.insert(test.begin() + 4, 4);

    for (int i : test)
        std::cout << i << std::endl;
    
    
}