// Problem source: https://leetcode.com/problems/invert-binary-tree/

// My Solution:
// Runtime : 0ms
// Memory usage: 9.7 MB

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// In this problem, we always need to invert left and right if root is not nulltpr
class Solution
{
public:
    // swap right and left leaf
    void swapLeaf(TreeNode *root)
    {
        TreeNode *Temp = root->left;
        root->left = root->right;
        root->right = Temp;
    }

    // If root is nullptr, return itself
    // If not, recursive strategy
    // 1. swap two leaf in one root
    // 2. traverse next leaf(next root) recursively.
    // After traversal, the algorithm does one invertion of each of whole roots
    TreeNode *invertTree(TreeNode *root)
    {
        // base case
        if (root == nullptr)
        {
            return root;
        }
        else
        {
            swapLeaf(root);
            invertTree(root->left);
            invertTree(root->right);
        }

        return root;
    }
};