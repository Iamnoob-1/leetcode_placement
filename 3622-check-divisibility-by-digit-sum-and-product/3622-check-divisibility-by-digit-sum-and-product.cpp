class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int sum=0;
        int pro=1;
        while (n!=0){
            int dig=n%10;
            n=n/10;
            sum+=dig;
            pro*=dig;
        }
        if (num%(sum+pro)==0){
            return true;
        }
        return false;
    }
};