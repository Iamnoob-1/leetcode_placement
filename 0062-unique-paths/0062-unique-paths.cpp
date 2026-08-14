class Solution {
public:
    int recursion(int m,int n,vector<vector<int>>&dp){
        if (m==0&&n==0)return 1;
        if (m<0||n<0)return 0;
        if (dp[m][n]!=-1)return dp[m][n];
        int left=recursion(m,n-1,dp);
        int up=recursion(m-1,n,dp);
        return dp[m][n]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return recursion(m-1,n-1,dp);
    }
};