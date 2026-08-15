class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        bool zero=true;
        for (int i=0;i<n;i++){
            if (nums[i]!=0){
                zero=false;
            }
            ans=ans^nums[i];
        }
        if (zero)return 0;
        return ans!=0?n:n-1;
    }
};