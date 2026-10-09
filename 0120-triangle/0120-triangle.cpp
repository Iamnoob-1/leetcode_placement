class Solution {
public:
    int recursion(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if (i==triangle.size()-1)return triangle[i][j];
        if (dp[i][j]!=-1)return dp[i][j];
        int down=recursion(i+1,j,triangle,dp);
        int downright=recursion(i+1,j+1,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(down,downright);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for (int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for (int i=n-2;i>=0;i--){
            for (int j=0;j<=i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};