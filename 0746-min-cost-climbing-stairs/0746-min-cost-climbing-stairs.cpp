class Solution {
public:
    int recursion(int idx,vector<int>cost,vector<int>&dp){
        if (idx>=cost.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int onestep=cost[idx]+recursion(idx+1,cost,dp);
        int twostep=cost[idx]+recursion(idx+2,cost,dp);
        return dp[idx]=min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(recursion(0,cost,dp),recursion(1,cost,dp));
    }
};