class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // ??save the first occurence of each character if it matches with the other then it is isomorphic
        unordered_map<char,int>fors;
        unordered_map<char,int>fort;
        for (int i=0;i<s.size();i++){
            if (fors.find(s[i])==fors.end()){
                fors[s[i]]=i;
            }
            if (fort.find(t[i])==fort.end()){
                fort[t[i]]=i;
            }
            if (fors[s[i]]!=fort[t[i]])return false;

        }
        return true;
    }
};