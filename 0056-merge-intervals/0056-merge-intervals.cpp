class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for (auto it:intervals){
            if (ans.empty())ans.push_back(it);
            else{
                vector<int>&last=ans.back();
                if (it[0]<=last[1]){
                    last[1]=max(last[1],it[1]);
                }
                else{
                    ans.push_back(it);
                }
            }
        }
        
        return ans;
    }
};