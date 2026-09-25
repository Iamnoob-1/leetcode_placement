class Solution {
public:
    vector<int> nextsmallerelement(vector<int>&heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        for (int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty())ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>previoussmallerelement(vector<int>heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        for (int i=0;i<n;i++){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>pse=previoussmallerelement(heights);
        vector<int>nse=nextsmallerelement(heights);
        int maxi=INT_MIN;
        for (int i=0;i<heights.size();i++){
            maxi=max(maxi,(nse[i]-pse[i]-1)*heights[i]);
        }
        return maxi;
    }
};