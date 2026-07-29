class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moores voting algo
        int highest=nums[0];
        int count=1;
        for (int i=1;i<nums.size();i++){
            if(highest==nums[i])count++;
            else{
                count--;
            }
            if (count<=0){
                highest=nums[i];count=1;
            }
        }
        return highest;
    }
};