class Solution {
public:
    int largestrect(vector<int>&heights){
        int n=heights.size();
        int ans=0;
        for (int i=0;i<n;i++){
            int minh=INT_MAX;
            for (int j=i;j<n;j++){
                minh=min(minh,heights[j]);
                int width=j-i+1;
                int area=width*minh;
                ans=max(ans,area);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            int area=largestrect(height);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};