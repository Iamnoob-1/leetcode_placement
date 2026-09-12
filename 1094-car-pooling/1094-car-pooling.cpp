class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>journey;
        for(auto it:trips){
            int p=it[0];
            int s=it[1];
            int e=it[2];
            journey.push_back({s,p});
            journey.push_back({e,-p});
        }
        sort(journey.begin(),journey.end());
        int maxp=0;
        int currp=0;
        for (auto it:journey){
            currp+=it.second;
            maxp=max(maxp,currp);
        }
        if (maxp>capacity)return false;
        return true;
    }
};