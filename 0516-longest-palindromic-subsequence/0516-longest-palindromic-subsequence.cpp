class Solution {
public:
    // int recursion(int idx1,int idx2,string s1,string s2,vector<vector<int>>&dp){
    //     if (idx1<0||idx2<0)return 0;
    //     if (s1[idx1]==s2[idx2])return dp[idx1][idx2]=1+recursion(idx1-1,idx2-1,s1,s2,dp);
    //     return dp[idx1][idx2]=max(recursion(idx1-1,idx2,s1,s2,dp),recursion(idx1,idx2-1,s1,s2,dp));
    // }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
         for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (s[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n]+1;
    }
};