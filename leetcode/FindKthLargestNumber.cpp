#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        map<int, int> m;
        int res;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end())
            {
                m.insert(make_pair(nums[i], 1));
            }
            else
            {
                m[nums[i]]++;
            }
        }

        map<int, int>::reverse_iterator it;
        int balance = k;
        for (it = m.rbegin(); it != m.rend(); ++it)
        {
            balance -= it->second;
            if (balance <= 0)
            {
                res = it->first;
                break;
            }
        }

        return res;
    }
};
