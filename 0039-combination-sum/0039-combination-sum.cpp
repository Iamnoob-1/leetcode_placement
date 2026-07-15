class Solution {
public:
    void recursion(int index,int currsum,vector<int>candidates,int target,vector<int>&subset,vector<vector<int>>&ans){
        if (index>=candidates.size() || currsum>target){
            return ;
        }
        if (currsum==target){
            ans.push_back(subset);
            return ;
        }
        //include
        subset.push_back(candidates[index]);
        recursion(index,currsum+candidates[index],candidates,target,subset,ans);
        //exclude
        subset.pop_back();
        recursion(index+1,currsum,candidates,target,subset,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subset;
        recursion(0,0,candidates,target,subset,ans);
        return ans;
    }
};