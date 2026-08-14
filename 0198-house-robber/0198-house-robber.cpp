class Solution {
public:
    int recursion(int idx,vector<int>&nums,vector<int>&dp){
        if (idx==0)return nums[0];
        if (idx==1)return max(nums[0], nums[1]);
        if (idx<0)return 0;
        if (dp[idx]!=-1)return dp[idx];
        int pick=nums[idx]+recursion(idx-2,nums,dp);
        int notpick=recursion(idx-1,nums,dp);
        return dp[idx]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return recursion(n-1,nums,dp);
    }
};