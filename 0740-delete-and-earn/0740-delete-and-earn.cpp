class Solution {
public:
    int recursion(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        //find all occurences of nums[idx]
        int i=idx+1;
        int count=1;
        while(i<nums.size() && nums[idx]==nums[i]){
            count++;
            i++;
        }
        //find all ocuurences of nums[idx+1]
        int j=i;
        while(j<nums.size() && nums[idx]+1==nums[j]){
            j++;
        }
        int nottake=recursion(i,nums,dp);
        int take=(count*nums[idx])+recursion(j,nums,dp);
        return dp[idx]=max(take,nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),-1);
        return recursion(0,nums,dp);
    }
};