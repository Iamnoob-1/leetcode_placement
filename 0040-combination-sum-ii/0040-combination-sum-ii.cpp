class Solution {
public:
    void recursion(int index,int currsum,vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&subset){
        if (currsum==target){
            ans.push_back(subset);
            return ;
        }
        if (index>=candidates.size()||currsum>target)return ;
        //include
        subset.push_back(candidates[index]);
        recursion(index+1,currsum+candidates[index],candidates,target,ans,subset);
        //exclude
        subset.pop_back();
         //find duplicates and skip them at same recursion lvel so that in output no 2 subsets are same 
        while (index+1<candidates.size()&& candidates[index]==candidates[index+1]){
            index++;
        }

        recursion(index+1,currsum,candidates,target,ans,subset);


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>subset;
        recursion(0,0,candidates,target,ans,subset);
        return ans;
    }
};