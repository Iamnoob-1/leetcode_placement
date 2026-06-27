class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=1;
        unordered_map<long long ,int>mp;
        for (auto num:nums){
            mp[num]++;
        }
        if (mp.count(1)){
            if (mp[1]%2==0){
                ans=max(ans,mp[1]-1);
            }
            else{
                ans=max(ans,mp[1]);
            }
        }
        for (auto &it:mp){
            int num=it.first;
            int freq=it.second;
            long long x=num;
            int len=0;
            if (num==1)continue;
            while (mp.count(x)&& mp[x]>=2){
                
                len+=2;
                if (x>LLONG_MAX/x)break;
                x*=x;
            }
             if (mp.count(x))
                len++;
            else
                len--;

            ans = max(ans, len);
        }
        return ans;

    }
};