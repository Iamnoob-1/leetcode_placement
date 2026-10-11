class Solution {
public:
    bool recursion(int idx,int remtarget,vector<int>&nums,vector<vector<int>>&dp){
        if (remtarget==0)return true;
        if (idx<=0)return false;
        if (remtarget<0)return false;
        
        if (dp[idx][remtarget]!=-1)return dp[idx][remtarget];
        bool take=recursion(idx-1,remtarget-nums[idx],nums,dp);
        bool nottake=recursion(idx-1,remtarget,nums,dp);
        return dp[idx][remtarget]=take||nottake;
    }

    bool canPartition(vector<int>& nums) {
        int total=0;
        for (int num:nums){
            total+=num;
        }
        if (total%2!=0)return false;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return recursion(n-1,total/2,nums,dp);
    }
};