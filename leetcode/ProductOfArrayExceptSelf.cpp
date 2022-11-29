#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // product container
        int product = 1;
        // check if there is zero in vector
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // product whole elements except for zeros
            if (nums[i] == 0)
            {
                zeroCount++;
                continue;
            }
            else
            {
                product *= nums[i];
            }
        }

        // result vector to return
        vector<int> res(nums.size(), 0);
        // if there is more than one zero in vector, return zero initialized res vector
        if (zeroCount > 1)
        {
            return res;
        }
        // if zero count is exactly one, change the element corresponding to the index of zero to product result
        else if (zeroCount == 1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    res[i] = product;
                    break;
                }
            }
        }
        // if there is no zero, change the value of current index to product reuslt divided by current number.
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                res[i] = product / nums[i];
            }
        }

        return res;
    }
};