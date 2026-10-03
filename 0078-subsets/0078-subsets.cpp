class Solution {
public:
    void recursion(int idx,vector<int>&nums,vector<int>&subset,vector<vector<int>>&ans){
        if (idx>=nums.size()){
            ans.push_back(subset);
            return ;
        }
        //include
        subset.push_back(nums[idx]);
        recursion(idx+1,nums,subset,ans);
        subset.pop_back();
        recursion(idx+1,nums,subset,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>ans;
        recursion(0,nums,subset,ans);
        return ans;
    }
};