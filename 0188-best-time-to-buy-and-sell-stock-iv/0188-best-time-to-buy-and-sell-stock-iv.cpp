class Solution {
public:
     int recursion(int idx,int buy,vector<int>&prices,vector<vector<vector<int>>>&dp,int count){
        if (count==0)return 0;
        if (idx>=prices.size())return 0;
        if (dp[idx][buy][count]!=-1)return dp[idx][buy][count];
        if (buy){
            int take=-prices[idx]+recursion(idx+1,0,prices,dp,count);
            int nottake=recursion(idx+1,1,prices,dp,count);
            return dp[idx][buy][count]=max(take,nottake);
        }
        else{
            int sell=prices[idx]+recursion(idx+1,1,prices,dp,count-1);
            int notsell=recursion(idx+1,0,prices,dp,count);
            return dp[idx][buy][count]=max(sell,notsell);
        }
    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return recursion(0,1,prices,dp,k);
    }
};