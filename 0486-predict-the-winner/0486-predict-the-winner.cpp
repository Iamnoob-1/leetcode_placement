class Solution {
public:
    int recursion(int l,int r,int turn,vector<int>&nums,vector<vector<vector<int>>>& dp){
        if (l == r) {
            if (turn == 0)
                return nums[l];
            return 0;
        }
        if (dp[l][r][turn]!=-1)return dp[l][r][turn];
        if (turn==0){
            return dp[l][r][0]=max(nums[l]
            +recursion(l+1,r,1,nums,dp),nums[r]+recursion(l,r-1,1,nums,dp));
        }
        if (turn==1){
            return dp[l][r][1]=min(recursion(l+1,r,0,nums,dp),recursion(l,r-1,0,nums,dp));
        }
        return INT_MIN;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,
    vector<vector<int>>(n, vector<int>(2, -1)));
        int p1 = recursion(0, nums.size()-1,0,nums,dp);
        int total=0;
        for (int num:nums){
            total+=num;
        }
        int p2=total-p1;
        return p1>=p2;
    }
};