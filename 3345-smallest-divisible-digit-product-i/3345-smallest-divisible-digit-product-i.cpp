class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true){
            int num=n;
            int pro=1;
            while(num){
                int dig=num%10;
                pro*=dig;
                num/=10;
            }
            if (pro%t==0){
                return n;
            }
            else{
                n+=1;
            }
        }
        return -1;
    }
};