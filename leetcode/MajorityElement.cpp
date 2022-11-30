#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
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

        vector<pair<int, int>> mapVec(countMap.begin(), countMap.end());
        sort(mapVec.begin(), mapVec.end(), [](pair<int, int> p1, pair<int, int> p2)
             { return p1.second > p2.second; });

        return mapVec[0].first;
    }
};