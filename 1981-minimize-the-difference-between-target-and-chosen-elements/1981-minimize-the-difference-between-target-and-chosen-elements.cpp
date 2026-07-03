class Solution {
public:
    int recursion(int n,int m ,int i,int sum,vector<vector<int>>&dp,int target,vector<vector<int>>&mat){
        if (i==n){
            return abs(target-sum);
            
        }
        if (dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans=INT_MAX;
        for (int j=0;j<m;j++){
            ans=min(ans,recursion(n,m,i+1,sum+mat[i][j],dp,target,mat));
        }
        return dp[i][sum]=ans;


    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(4901,-1));
        return recursion(n,m,0,0,dp,target,mat);
        
    }
};