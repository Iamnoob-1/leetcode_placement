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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,1});
        long long ans=0;
        while (!q.empty()){
            int n=q.size();
            long long left=0;
            long long right=0;
            long long first = q.front().second;
            for (int i=0;i<n;i++){
                auto[node,idx]=q.front();
                q.pop();
                idx-=first;
                if (i==0)left=idx;
                if (i==n-1)right=idx;
                if (node->left)q.push({node->left,2*idx+1});
                if (node->right)q.push({node->right,2*idx+2});
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};