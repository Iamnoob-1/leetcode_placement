class Solution {
public:
    int recursion(string &w1,string&w2,int i,int j,vector<vector<int>>&dp){
        if (j<0)return i+1;
        if(i<0)return j+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if (w1[i]==w2[j]){
            return dp[i][j]=recursion(w1,w2,i-1,j-1,dp);
        }
        int ins=1+recursion(w1,w2,i,j-1,dp);
        int rep=1+recursion(w1,w2,i-1,j-1,dp);
        int del=1+recursion(w1,w2,i-1,j,dp);
        return dp[i][j]=min(ins,min(rep,del));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recursion(word1,word2,n-1,m-1,dp);
    }
};