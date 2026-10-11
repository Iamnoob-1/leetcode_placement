class Solution {
public:
    int recursion(int idx,int target,vector<int>&nums){
        if (idx<0)return target==0;
        int add=recursion(idx-1,target-nums[idx],nums);
        int sub=recursion(idx-1,nums[idx]+target,nums);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return recursion(n-1,target,nums);
    }
};