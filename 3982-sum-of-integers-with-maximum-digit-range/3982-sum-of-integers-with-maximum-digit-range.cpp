class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxdig=INT_MIN;
        for (int num:nums){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            while(num){
                int dig=num%10;
                maxi=max(maxi,dig);
                mini=min(mini,dig);
                num/=10;
            }

            maxdig=max(maxi-mini,maxdig);
        }
        int sum=0;
        for (int num:nums){
            int temp=num;
            int maxi=INT_MIN;
            int mini=INT_MAX;
            while(num){
                int dig=num%10;
                maxi=max(maxi,dig);
                mini=min(mini,dig);
                num/=10;
            }
            if (maxi-mini==maxdig){
                sum+=temp;
            }
        }
        return sum;
    }
};