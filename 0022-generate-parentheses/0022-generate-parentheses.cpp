class Solution {
public:
    void recursion(int open,int close,int n,vector<string>&ans,string subset){
        if (subset.size()==2*n){
            ans.push_back(subset);
            return ;
        }
        if (open<n){
            recursion(open+1,close,n,ans,subset+"(");
        }
        if (close<open){
            recursion(open,close+1,n,ans,subset+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string subset="";
        recursion(0,0,n,ans,subset);
        return ans;
    }
};