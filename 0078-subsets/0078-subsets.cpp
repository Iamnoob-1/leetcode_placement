class Solution {
public:
    void recursion(int index,vector<int>&nums,vector<int>&subset,vector<vector<int>>&ans){
        if (index>=nums.size()){
            ans.push_back(subset);
            return;
        }
        //exclude
        recursion(index+1,nums,subset,ans);
        //include
        subset.push_back(nums[index]);
        recursion(index+1,nums,subset,ans);
        subset.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        recursion(0,nums,subset,ans);
        return ans;
    }
};