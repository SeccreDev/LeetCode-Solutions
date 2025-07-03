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
class Solution {
public:
    bool balanced = true;

    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr)
        {
            return balanced;
        }

        DFS(root);
        return balanced;
    }
    
    int DFS(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int maxLeft = DFS(root->left);
        int maxRight = DFS(root->right);
        
        if(abs(maxRight - maxLeft) > 1)
        {
            balanced = false;
        }
        return max(maxLeft, maxRight) + 1;
    }
};