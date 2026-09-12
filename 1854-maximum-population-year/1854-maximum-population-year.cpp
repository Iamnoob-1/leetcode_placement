class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>pop;
        for (auto it:logs){
            pop.push_back({it[0],1});
            pop.push_back({it[1],-1});
        }
        sort(pop.begin(),pop.end());
        int year=0;
        int maxp=0;
        int currp=0;
        for (auto it:pop){
            currp+=it.second;
            if (maxp<currp){
                maxp=currp;
                year=it.first;
            }
        }
        return year;
    }
};