class Solution {
public:
    int recursion(int idx,vector<int>&nums,vector<vector<int>>&dp,int prev){
        if(idx>=nums.size())return 0;
        if (dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        int take=-1;
        if (prev==-1||nums[idx]>nums[prev])
            take=1+recursion(idx+1,nums,dp,idx);
        int nottake=recursion(idx+1,nums,dp,prev);
        return dp[idx][prev+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recursion(0,nums,dp,-1);
    }
};