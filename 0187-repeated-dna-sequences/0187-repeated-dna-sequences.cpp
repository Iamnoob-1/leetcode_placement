class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if (n<10)return {};
        unordered_set<string>unique;
        unordered_set<string>st;
        for (int i=0;i<=n-10;i++){
            string temp=s.substr(i,10);
            if (st.find(temp)==st.end()){
                st.insert(temp);
                temp="";
            }
            else{
                unique.insert(temp);
                // ans.push_back(temp);
            }
        }
        vector<string>ans(unique.begin(), unique.end());
        return ans;
    }
};