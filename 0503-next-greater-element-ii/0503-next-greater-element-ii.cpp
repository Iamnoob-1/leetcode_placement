class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n);
        for (int i=2*n-1;i>=0;i--){
            int currele=nums[i%n];
            while(!st.empty() && st.top()<=currele){
                st.pop();
            }
            if (i<n){
                if (st.empty()){
                    ans[i]=-1;
                }
                else{
                    ans[i]=st.top();
                }
                
            }
            st.push(currele);
        }
        return ans;
    }
};