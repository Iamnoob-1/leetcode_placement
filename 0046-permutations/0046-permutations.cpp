class Solution {
public:
    void recursion(int idx,vector<int>nums,vector<int>&subset,vector<vector<int>>&ans,vector<bool>&used){
        if (idx==nums.size()){
            ans.push_back(subset);
            return ;
        }
        for (int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            subset.push_back(nums[i]);
            used[i]=true;
            recursion(idx+1,nums,subset,ans,used);
            used[i]=false;
            subset.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>ans;
        vector<bool> used(nums.size(), false);
        recursion(0,nums,subset,ans,used);
        return ans;
    }
};