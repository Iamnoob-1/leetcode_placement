class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int total=n*m;
        int count=0;
        int top=0,bottom=n-1,left=0,right=m-1;
        while(count<total){
            for (int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            for (int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            if (count<total){
                for (int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;
            }
            if (count<total){
                for (int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
            }
        }
        return ans;
    }
};