#include <util/timer.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        std::unordered_map<int,int> candidateFrequencies;

        for (int& num : candidates)
        {
            auto elem = candidateFrequencies.find(num);
            if (elem == candidateFrequencies.end())
                candidateFrequencies.insert({num, 1});
            else
                ++elem->second;            
        }

        std::vector<int> numsSoFar;
        numsSoFar.reserve(candidates.size());
        std::vector<std::vector<int>> results;
        internalCombinationSum2(candidateFrequencies, numsSoFar, 0, target, candidateFrequencies.begin(), results);

        return results;
    }

    void internalCombinationSum2(std::unordered_map<int, int>& candidateFrequencies, std::vector<int>& numsSoFar, int sumSoFar, int target, std::unordered_map<int, int>::iterator iter, std::vector<std::vector<int>>& results)
    {
        if (sumSoFar == target)
        {
            results.push_back(numsSoFar);
            return;
        }
        
        if (iter == candidateFrequencies.end() || sumSoFar > target)
            return;
        std::cout << "Iter: " << iter->first << " " << iter->second << std::endl;

        int i = 0;
        int additions = 0;
        while (i < iter->second+1 && (sumSoFar + additions) <= target)
        {
            internalCombinationSum2(candidateFrequencies, numsSoFar, sumSoFar + additions, target, std::next(iter), results);
            additions += iter->first;
            numsSoFar.push_back(iter->first);
            ++i;
        }

        for (int j = 0; j < i; ++j)
            numsSoFar.pop_back();
    }
};


class Solution2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> numsSoFar;
        numsSoFar.reserve(candidates.size());
        std::vector<std::vector<int>> results;
        internalCombinationSum2(candidates, numsSoFar, 0, target, 0, results);

        return results;
    }

    void internalCombinationSum2(std::vector<int>& candidates, std::vector<int>& numsSoFar, int sumSoFar, int target, int offset, std::vector<std::vector<int>>& results)
    {
        if (sumSoFar == target)
        {
            results.push_back(numsSoFar);
            return;
        }

        if (offset >= candidates.size() || sumSoFar > target)
            return;

        numsSoFar.push_back(candidates[offset]);
        internalCombinationSum2(candidates, numsSoFar, sumSoFar + candidates[offset], target, offset + 1, results);
        numsSoFar.pop_back();
        
        while (offset + 1 < candidates.size() && candidates[offset] == candidates[offset+1])
            ++offset;
        internalCombinationSum2(candidates, numsSoFar, sumSoFar, target, offset + 1, results);

    }
};
