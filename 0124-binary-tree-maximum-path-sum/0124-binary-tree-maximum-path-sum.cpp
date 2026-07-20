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
    int recursion(TreeNode* root,int &maxi){
        if (!root)return 0;
        int leftside=max(0,recursion(root->left,maxi));
        int rightside=max(0,recursion(root->right,maxi));
        maxi=max(root->val+leftside+rightside,maxi);
        return root->val+max(leftside,rightside);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        recursion(root,maxi);
        return maxi;
    }
};