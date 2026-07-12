class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>copy=arr;
        unordered_map<int,int>rank;
        sort(copy.begin(),copy.end());
        int r=1;
        for (int num:copy){
            if (!rank.count(num)){
                rank[num]=r++;
            }
        }
        vector<int>ans;
        for (int x:arr){
            ans.push_back(rank[x]);
        }
        return ans;
    }
};