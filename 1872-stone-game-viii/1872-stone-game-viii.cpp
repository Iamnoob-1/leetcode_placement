class Solution {
public:
    int recursion(int idx,vector<int>&prefix,vector<int>&dp){
        if(idx>=prefix.size()){
            return 0;
        }
        if(idx==prefix.size()-1)return prefix[idx];
        if(dp[idx]!=-1)return dp[idx];
        int take=prefix[idx]-recursion(idx+1,prefix,dp);
        int nottake=recursion(idx+1,prefix,dp);
        return dp[idx]=max(take,nottake);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefix(n);
        prefix[0]=stones[0];
        for (int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        vector<int>dp(n,-1);
        dp[n - 1] = prefix[n - 1];
        int ans=0;
        for (int i=n-2;i>=1;i--){
            int take=prefix[i]-dp[i+1];
            int nottake=dp[i+1];
            dp[i]=max(take,nottake);
        }
        return dp[1];
        // return recursion(1,prefix,dp);
    }
};