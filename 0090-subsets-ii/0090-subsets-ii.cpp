class Solution {
public:
    void recursion(int index,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&subset){
        if (index>=candidates.size()){
            ans.push_back(subset);
            return ;
        }
        //include
        subset.push_back(candidates[index]);
        recursion(index+1,candidates,ans,subset);
        //exclude
        subset.pop_back();
         //find duplicates and skip them at same recursion lvel so that in output no 2 subsets are same 
        while (index+1<candidates.size()&& candidates[index]==candidates[index+1]){
            index++;
        }

        recursion(index+1,candidates,ans,subset);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>subset;
        recursion(0,nums,ans,subset);
        return ans;
    }
};