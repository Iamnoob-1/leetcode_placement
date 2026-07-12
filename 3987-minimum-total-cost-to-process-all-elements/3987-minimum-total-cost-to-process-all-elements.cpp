class Solution {
public:
    int mod=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long sum=0;
        for (int num:nums){
            sum+=num;
        }
        long long n=sum/k;
        if (sum%k==0){
            n=n-1;
        }
        long long a=n;
        long long b=n+1;
        if (a%2==0){
            a/=2;
        }
        else{
            b/=2;
        }
        return ((a%mod)*(b%mod))%mod;
        // long long ans=0;
        // for (int i=1;i<=n;i++){
        //     ans=(ans+(i%mod))%mod;
        // }
        // return (((n%mod)*(n+1)%mod)%mod)/2;
        
    }
};