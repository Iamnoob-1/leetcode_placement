class Solution {
public:
    int recursion(int i,int j,vector<int>&piles,vector<vector<int>>&dp){
        if(i>j)return 0;
        // if(i==j)return piles[i];
        if (dp[i][j]!=-1)return dp[i][j];
        int take_i=piles[i]+min(recursion(i+1,j-1,piles,dp),recursion(i+2,j,piles,dp));
        int take_j=piles[j]+min(recursion(i,j-2,piles,dp),recursion(i+1,j-1,piles,dp));
        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int alice=recursion(0,n-1,piles,dp);
        int total=0;
        for (int num:piles){
            total+=num;
        }
        return alice>total-alice;
        
    }
};