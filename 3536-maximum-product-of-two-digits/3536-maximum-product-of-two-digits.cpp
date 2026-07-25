class Solution {
public:
    int maxProduct(int n) {
        int maxi=0;
        int maxi2=0;
        while (n!=0){
            int dig=n%10;
            n/=10;
            if (dig>maxi){
                maxi2=maxi;
                maxi=dig;
            }
            else if (dig>maxi2)maxi2=dig;
        }
        return maxi*maxi2;
    }
};