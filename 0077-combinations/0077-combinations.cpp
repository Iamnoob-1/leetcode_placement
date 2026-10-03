class Solution {
public:
    void recursion(int idx,int n,int k,vector<int>&subset,vector<vector<int>>&ans){
        if(subset.size()==k){
            ans.push_back(subset);
            return;
        }
        for (int i=idx;i<=n;i++){
            subset.push_back(i);
            recursion(i+1,n,k,subset,ans);
            subset.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>subset;
        vector<vector<int>>ans;
        recursion(1,n,k,subset,ans);
        return ans;
    }
};