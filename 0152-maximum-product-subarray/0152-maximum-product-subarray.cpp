class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro=INT_MIN;
        int maxpro2=INT_MIN;
        int pro=1;
        for (int i=0;i<nums.size();i++){
            pro*=nums[i];
            maxpro=max(maxpro,pro);
            if (pro==0)pro=1;
        }
        pro=1;
        for (int i=nums.size()-1;i>=0;i--){
            pro*=nums[i];
            maxpro2=max(maxpro2,pro);
            if (pro==0)pro=1;
        }
        return max(maxpro,maxpro2);


    }
};