class Solution {
public:
    long long sumAndMultiply(int n) {
        int x=n;
        int sum=0;
        string str="";
        while(x){
            int dig=x%10;
            if (dig!=0){
                str+=to_string(dig);
                sum+=dig;
            }
            x=x/10;
        }
        if(str.size()==0)return 0;
        reverse(str.begin(),str.end());
        return 1LL*stoi(str)*sum;
    }
};