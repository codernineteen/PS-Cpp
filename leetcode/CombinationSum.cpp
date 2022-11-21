#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    vector<vector<int>> res;

public:
    void generateComb(int i, vector<int> &candidates, int target, vector<int> &copy_vec)
    {
        if (target == 0)
        {
            res.push_back(copy_vec);
            return;
        }
        while (i < candidates.size() && target - candidates[i] >= 0)
        {
            copy_vec.push_back(candidates[i]);
            generateComb(i, candidates, target - candidates[i], copy_vec);
            ++i;
            copy_vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> input_vec;
        sort(candidates.begin(), candidates.end());
        generateComb(0, candidates, target, input_vec);

        return res;
    }
};