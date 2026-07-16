class Solution {
public:
    int gcd(int a ,int b){
        if (b==0)return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixgcd;
        int maxi=INT_MIN;
        for (int num:nums){
            maxi=max(maxi,num);
            prefixgcd.push_back(gcd(maxi,num));
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long ans=0;
        int left=0;
        int right=nums.size()-1;
        while (left<right){
            ans+=gcd(prefixgcd[left++],prefixgcd[right--]);
        }
        return ans;
    }
};