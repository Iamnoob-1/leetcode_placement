class Solution {
public:
    int recursion(int idx,int amountleft,vector<int>&coins,vector<vector<int>>&dp){
        if (idx>=coins.size())return 0;
        if (amountleft==0)return 1;
        if(amountleft<0)return 0;
        if (dp[idx][amountleft]!=-1)return dp[idx][amountleft];
        int take=recursion(idx,amountleft-coins[idx],coins,dp);
        int nottake=recursion(idx+1,amountleft,coins,dp);
        return dp[idx][amountleft]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return recursion(0,amount,coins,dp);
    }
};