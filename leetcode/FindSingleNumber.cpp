// Problem
//  source: https://leetcode.com/problems/single-number/submissions/

// Solution(solved by myself)
// runtime : 92ms , faster than 5.59% (optimization needed)
// memory usage : 20.7mb
// can i optimize this by using greedy algorithm?
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res;
        map<int, int> memo;
        map<int, int>::iterator it;
        for (auto num : nums)
        {
            if (memo.find(num) == memo.end())
            {
                memo.insert(make_pair(num, 1));
            }
            else
            {
                it = memo.find(num);
                it->second += 1;
            }
        }

        for (auto iter = memo.begin(); iter != memo.end(); iter++)
        {
            if (iter->second == 1)
            {
                res = iter->first;
            }
        }

        return res;
    }
};
