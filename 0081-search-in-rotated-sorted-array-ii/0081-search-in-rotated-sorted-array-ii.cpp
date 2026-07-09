class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while (low<=high){
            int mid =low+(high-low)/2;
            if (nums[mid]==target){
                return true;
            }
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {// we dont know which half is sorted so we do this 
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid]){
                if (target<nums[mid]&& target>=nums[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if (target<=nums[high]&& target>nums[mid]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};