class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=INT_MIN;
        int mincosttillindexi=prices[0];
        for(int i=1;i<prices.size();i++){
            int cost=prices[i]-mincosttillindexi;
            maxi=max(maxi,cost);
            mincosttillindexi=min(mincosttillindexi,prices[i]);
        }
        return maxi<0?0:maxi;
    }
};