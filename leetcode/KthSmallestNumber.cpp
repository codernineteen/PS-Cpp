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
    // record numbers while doing in-order traversal
    vector<int> spreadTree;

public:
    void helper(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        helper(root->left);
        spreadTree.push_back(root->val);
        helper(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        helper(root);
        return spreadTree[k - 1]; // kth-smallest number
    }
};