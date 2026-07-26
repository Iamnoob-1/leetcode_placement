class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int first=nums[n-1]*nums[n-2]*nums[n-3];
        int second=nums[0]*nums[1]*nums[n-1];
        return max(first,second);
    }
};