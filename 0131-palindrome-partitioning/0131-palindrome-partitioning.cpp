class Solution {
public:
    bool ispalindrome(int left,int right,string&s){
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void recursion(int index,string s,vector<vector<string>>&ans,vector<string>&subset){
        if(index>=s.size()){
            ans.push_back(subset);
            return;
        }
        for (int end=index;end<s.size();end++){
            if (ispalindrome(index,end,s)){
                subset.push_back(s.substr(index,end-index+1));
                recursion(end+1,s,ans,subset);
                subset.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>subset;
        recursion(0,s,ans,subset);
        return ans;
    }
};