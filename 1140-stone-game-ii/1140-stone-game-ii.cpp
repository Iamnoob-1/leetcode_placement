class Solution {
public:
int recursion(int i,int m,vector<vector<int>>&dp,vector<int>&suffix){
    int n=suffix.size()-1;
    if(i>=suffix.size()-1)return 0;
    if(i+2*m>=n)return suffix[i];
    if(dp[i][m]!=-1)return dp[i][m];
    int ans=0;
    for(int x=1;x<=2*m;x++){
        ans=max(ans,suffix[i]-recursion(i+x,max(m,x),dp,suffix));
    }
    return dp[i][m]=ans;
}
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int>suffix(n+1,0);
        for (int i=n-1;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recursion(0,1,dp,suffix);
    }
};