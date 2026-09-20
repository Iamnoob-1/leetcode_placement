class Solution {
public:
    int recursion(int idx,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if (idx>=n-1)return 0;
        if (dp[idx]!=-1)return dp[idx];
        int ans=INT_MAX;
        for (int i=1;i<=nums[idx];i++){
            int checkforinfi=recursion(idx+i,nums,dp);
            if (checkforinfi!=INT_MAX){
                ans=min(ans,1+checkforinfi);
            }
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return recursion(0,nums,dp);
    }
};