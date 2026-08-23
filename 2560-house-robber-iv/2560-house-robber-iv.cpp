class Solution {
public:
    bool canrob(vector<int>nums,int k,int mid){
        int count=0;
        for (int i=0;i<nums.size();){
            if (nums[i]<=mid){
                count++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while (low <= high) {
            int mid=low+(high-low)/2;
            if (canrob(nums,k,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;

    }
};