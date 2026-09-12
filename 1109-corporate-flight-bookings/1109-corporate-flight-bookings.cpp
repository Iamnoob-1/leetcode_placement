class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        vector<pair<int,int>>seat;
        for (auto it:bookings){
            int f=it[0];
            int s=it[1];
            int r=it[2];
            ans[f-1]+=r;
            if(s<n)ans[s]-=r;
        }
        for (int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        return ans;


    }
};