/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    public:
        int diameterOfBinaryTree(TreeNode* root)
        {
            int diameter = INT_MIN;
            maxDepth(root, diameter);
            return diameter;
        }

        int maxDepth(TreeNode* root, int &diameter)
        {
            if (root == nullptr)
            {
                return 0;
            }
            int maxLeft = maxDepth(root->left, diameter);
            int maxRight = maxDepth(root->right, diameter);
            diameter = max(diameter, maxLeft + maxRight);
            return max(maxLeft, maxRight) + 1;
        }
};