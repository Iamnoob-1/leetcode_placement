class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        for (char c:t){
            freq[c]++;
        }
        int count=t.size();
        int left=0;
        int right=0;
        int mini=INT_MAX;
        int start=0;
        while(right<s.size()){
            if(freq[s[right]]>0){
                count--;
            }
            freq[s[right]]--;
            while(count==0){
                  if(right-left+1<mini){
                    mini=right-left+1;
                    start=left;
                  }
                  freq[s[left]]++;
                  if(freq[s[left]]>0)count++;
                  left++;
            }
            right++;

        }
        if (mini == INT_MAX)       
            return "";

        return s.substr(start, mini);
    }
};