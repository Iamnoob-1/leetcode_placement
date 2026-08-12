class Solution {
public:
    bool recursion(int n,vector<int>&dp){
        if (n==0)return false;
        if (n==1)return true;
        if (dp[n]!=-1)return dp[n];
        for (int i=1;i*i<=n;i++){
             if(recursion(n -i*i,dp)==false)
            return dp[n] = true;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return recursion(n,dp);
        
    }
};