/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()){
            int n=q.size();
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                mp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right]=curr;
                q.push(curr->right);
            }
        }
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        while (!q.empty()){
            int n=q.size();
            if (k==0){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            k--;
            for (int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                 if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (mp.count(node) && !visited.count(mp[node])) {
                    visited.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
        }
        return ans;
    }
};