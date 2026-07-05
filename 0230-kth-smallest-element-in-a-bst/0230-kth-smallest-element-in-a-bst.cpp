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
    void solve(TreeNode*root,int &c,int &ans,int k){
        if (root==NULL)return ;
        solve(root->left,c,ans,k);
        c++;
        if (c==k){
            ans=root->val;
            return ;
        }
        solve(root->right,c,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int c=0;
        solve(root,c,ans,k);
        return ans;
    }
};