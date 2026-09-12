class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        vector<pair<int,int>>seat;
        for (auto it:bookings){
            int f=it[0];
            int s=it[1];
            int r=it[2];
            seat.push_back({f,r});
            seat.push_back({s+1,-r});
        }
        sort(seat.begin(),seat.end());
        int currsum=0;
        int j = 0;
        for (int i=1;i<=n;i++){
            while (j<seat.size()&&seat[j].first==i) {
                currsum += seat[j].second;
                j++;
            }
            ans[i-1]=currsum;
        }

        return ans;


    }
};