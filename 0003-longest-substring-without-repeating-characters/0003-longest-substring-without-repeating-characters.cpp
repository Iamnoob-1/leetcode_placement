class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;
        while(j<n){
            if (mp.find(s[j])!=mp.end()){
                mp.erase(s[i]);
                i++;
            }
            else{
                mp[s[j]]++;
                ans=max(ans,j-i+1);
                j++;
            }

        }
        return ans;
    }
};