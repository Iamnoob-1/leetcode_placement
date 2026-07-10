class Solution {
public:
    string removeOuterParentheses(string s) {

        int open=0;
        int close=0;
        string ans="";
        string temp="";
        for (char ch:s){
            if (ch=='(')open++;
            if (ch==')')close++;
            temp+=ch;
            if (open==close){
                if (temp.size()>2){
                    temp=temp.substr(1);
                    temp=temp.substr(0,temp.size()-1);
                    ans+=temp;
                    temp="";
                    open=0;
                    close=0;
                }
                else{
                    temp="";
                    open=0;
                    close=0;
                }
            }
        }
        return ans;
//         I kept three things:

// open → counts '('
// close → counts ')'
// temp → stores the current primitive
// While looping through the string:

// Increase open when I see '('.
// Increase close when I see ')'.
// Keep adding characters into temp.
// Whenever open == close, it means one primitive is complete.
// If the primitive is just "()", nothing remains after removing the outer pair, so I ignore it.
// Otherwise, I remove the first and last character using substring() and append the remaining part to the answer.
// Finally, I reset everything and start collecting the next primitive.
    }
};