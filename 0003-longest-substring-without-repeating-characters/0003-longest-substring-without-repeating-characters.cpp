class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mp;
        while (j<s.size()){
            if (mp.find(s[j])!=mp.end()){
                mp.erase(s[i]);
                i++;
            }
            else{
                mp[s[j]]=j;
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};