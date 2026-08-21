class Solution {
public:
     int recursion(int idx,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee){
        if (idx>=prices.size())return 0;
        if (dp[idx][buy]!=-1)return dp[idx][buy];
        if (buy){
            int take=-prices[idx]+recursion(idx+1,0,prices,dp,fee);
            int nottake=recursion(idx+1,1,prices,dp,fee);
            return dp[idx][buy]=max(take,nottake);
        }
        else{
            int sell=prices[idx]+recursion(idx+1,1,prices,dp,fee)-fee;
            int notsell=recursion(idx+1,0,prices,dp,fee);
            return dp[idx][buy]=max(sell,notsell);
        }
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return recursion(0,1,prices,dp,fee);
    }
};