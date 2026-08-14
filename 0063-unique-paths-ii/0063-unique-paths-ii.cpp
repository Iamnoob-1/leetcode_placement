class Solution {
public:
    int recursion(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if (i<0||j<0||matrix[i][j]==1)return 0;
        if (i==0&&j==0)return 1;
        if (dp[i][j]!=-1)return dp[i][j];
        int left=recursion(i,j-1,matrix,dp);
        int up=recursion(i-1,j,matrix,dp);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recursion(n-1,m-1,obstacleGrid,dp);
    }
};