class Solution {
public:
    bool recursion(int index,int target,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if (sum==target)return true;
        if (index>=nums.size())return false;
        if (dp[index][sum]!=-1)return dp[index][sum];

        bool take = recursion(index+1,target,nums,sum+nums[index],dp);
        bool nottake = recursion(index+1,target,nums,sum,dp);
        return dp[index][sum]=take|| nottake;
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for (int num:nums){
            target+=num;
        }
        if (target%2!=0)return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return recursion(0,target/2,nums,0,dp);
    }
};