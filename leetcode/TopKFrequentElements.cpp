#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{

public:
    vector<pair<int, int>> sortMap(unordered_map<int, int> &m)
    {
        vector<pair<int, int>> mapToVec(m.begin(), m.end());

        sort(mapToVec.begin(), mapToVec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second > b.second; });

        return mapToVec;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> res;
        unordered_map<int, int> countMap;
        for (auto num : nums)
        {
            if (countMap.find(num) != countMap.end())
            {
                countMap[num] += 1;
            }
            else
            {
                countMap.insert(make_pair(num, 1));
            }
        }

        vector<pair<int, int>> sortedPairs;
        sortedPairs = sortMap(countMap);

        for (int i = 0; i < k; i++)
        {
            res.push_back(sortedPairs[i].first);
        }

        return res;
    }
};