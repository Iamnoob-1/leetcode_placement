class Solution {
public:
    int square(int num){
        int ans=0;
        while(num){
            int dig=num%10;
            ans+=dig*dig;
            num/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow=square(n);
        int fast=square(square(n));
        while(slow!=fast){
            slow=square(slow);
            fast=square(square(fast));
        }
        return slow==1;
    }
};