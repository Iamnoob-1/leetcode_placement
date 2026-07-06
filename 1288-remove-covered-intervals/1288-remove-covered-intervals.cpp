class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if (a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans=0;
        int maxiend=INT_MIN;
        for (auto &it:intervals){
            int one=it[0];
            int second=it[1];
            if (second>maxiend){
                ans++;
                maxiend=second;
            }

        }
        return ans;
    }
};