class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size()<10)return {};
        unordered_map<string,int>freq;
        for (int i=0;i<=s.length()-10;i++){
            string temp="";
            for (int j=i;j<i+10;j++){
                temp+=s[j];
            }
            freq[temp]++;
        }
        vector<string>ans;
        for (auto it:freq){
            if (it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};