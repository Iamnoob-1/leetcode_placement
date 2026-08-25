class Solution {
public:
    int recursion(int idx,string &s,int &n,vector<int>&dp){
        if(idx>n)return 0;
        if (idx==n)return 1;
        if(dp[idx]!=-1)return dp[idx];
        if (s[idx]=='0')return 0;
        int only1=recursion(idx+1,s,n,dp);
        int only2=0;
        if (s[idx]=='1'||s[idx]=='2'&&s[idx+1]<='6'){
            only2=recursion(idx+2,s,n,dp);
        }
        return dp[idx]=only1+only2;

    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return recursion(0,s,n,dp);
    }
};