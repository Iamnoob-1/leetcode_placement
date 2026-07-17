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
    int recursion(TreeNode* root){
        if (!root)return 0;
        int leftheight=recursion(root->left)+1;
        int rightheight=recursion(root->right)+1;
        return max(leftheight,rightheight);
    }
    int maxDepth(TreeNode* root) {
        int ans=recursion(root);
        return ans;
    }
};