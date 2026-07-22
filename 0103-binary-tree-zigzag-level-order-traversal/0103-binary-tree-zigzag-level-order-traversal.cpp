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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        int idx=1;
        while (!q.empty()){
            int n=q.size();
            vector<int>level;
            for (int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if (curr->left)q.push(curr->left);
                if (curr->right)q.push(curr->right);
                level.push_back(curr->val);
            }
            if (idx%2==1)ans.push_back(level);
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);

            }
            idx++;
        }
        return ans;
    }
};