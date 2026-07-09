class Solution {
public:
    bool possible(vector<int>nums,int thresh,int divi){
        int total=0;
        for (int num:nums){
            if (num%divi!=0){
                total+=(num/divi)+1;
            }
            else{
                total+=num/divi;
            }
        }
        return total<=thresh;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while (low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,threshold,mid)){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};