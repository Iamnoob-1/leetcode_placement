class Solution {
public:
    bool recursion(int index,int remtarget,vector<int>&nums,vector<vector<int>>&dp){
        if (remtarget==0)return true;
        if (remtarget<0)return false;
        if (index<0)return false;
        if (dp[index][remtarget]!=-1)return dp[index][remtarget];

        bool take = recursion(index-1,remtarget-nums[index],nums,dp);
        bool nottake = recursion(index-1,remtarget,nums,dp);
        return dp[index][remtarget]=take|| nottake;
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for (int num:nums){
            target+=num;
        }
        int n=nums.size();
        if (target%2!=0)return false;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return recursion(n-1,target/2,nums,dp);
    }
};