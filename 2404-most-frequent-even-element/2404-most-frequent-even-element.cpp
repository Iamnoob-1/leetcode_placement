class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (int num:nums){
            if (num%2==0){
                mp[num]++;
            }
        }
        int ans=0;
        int maxi=0;
        for (auto it:mp){
            if (maxi<it.second || it.second==maxi && it.first<ans){
                maxi=it.second;
                ans=it.first;
            }
            
        }
        return maxi==0?-1:ans;

    }
};