class Solution {
public:
    int maxDepth(string s) {
        int countpar=0;
        int maxi=0;
        for (char ch:s){
            if (ch=='(')countpar++;
            if (ch==')')countpar--;
            maxi=max(maxi,countpar);
        }
        return maxi;
    }
};