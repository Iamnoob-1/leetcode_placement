class Solution {
public://{i,j,q}
    void recursion(int i,int k,int target,vector<vector<int>>&ans,vector<int>&subset,int currsum){
        if (subset.size()==k &&currsum==target){
            ans.push_back(subset);
            return ;
        }
        if (subset.size()>k ||currsum>target){
            return ;
        }
        for (int index=i;index<=9;index++){
            //include
            subset.push_back(index);
            recursion(index+1,k,target,ans,subset,currsum+index);
            //exclude
            subset.pop_back();
            //no need of other recursive call because of for loop
            // recursion(index+1,k,target,ans,subset,currsum);
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>subset;
        recursion(1,k,n,ans,subset,0);
        return ans;
    }
};