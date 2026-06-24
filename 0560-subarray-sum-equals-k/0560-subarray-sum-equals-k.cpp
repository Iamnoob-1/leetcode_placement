class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int presum=0;
        int ans=0;
        for (int num:nums){
            presum+=num;
            if (mp.find(presum-k)!=mp.end()){
                ans+=mp[presum-k];
            }
            mp[presum]++;
        }
        return ans;
    }
};