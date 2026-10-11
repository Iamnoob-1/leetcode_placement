class Solution {
public:
    int recursion(int idx,int amountleft,vector<int>&coins,vector<vector<int>>&dp){
        if (idx<0)return 0;
        if (amountleft==0)return 1;
        if(amountleft<0)return 0;
        if (dp[idx][amountleft]!=-1)return dp[idx][amountleft];
        int take=recursion(idx,amountleft-coins[idx],coins,dp);
        int nottake=recursion(idx-1,amountleft,coins,dp);
        return dp[idx][amountleft]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return recursion(n-1,amount,coins,dp);
        // for (int i = 0; i <= n; i++) {
        //     dp[i][0] = 1;
        // }
        // for (int i=n;i<=0;i--){
        //     for (int j=0;j<=amount+1;j++){
        //         dp[i][j]=dp[i][j-coins[i]]+dp[i+1][j];
        //     }
        // }
        // return dp[n]
    }
};