#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *generateBST(vector<int> &nums, int start, int end)
    {
        int length = end - start + 1;
        int pivotIdx = length % 2 == 0 ? ((length / 2) - 1) + start : ((length - 1) / 2) + start;

        if (pivotIdx == start && pivotIdx == end)
        {
            return new TreeNode(nums.at(pivotIdx));
        }
        else if (pivotIdx == start && pivotIdx != end)
        {
            return new TreeNode(nums.at(pivotIdx), nullptr, generateBST(nums, pivotIdx + 1, end));
        }

        return new TreeNode(nums.at(pivotIdx), generateBST(nums, start, pivotIdx - 1), generateBST(nums, pivotIdx + 1, end));
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return generateBST(nums, 0, nums.size() - 1);
    }
};