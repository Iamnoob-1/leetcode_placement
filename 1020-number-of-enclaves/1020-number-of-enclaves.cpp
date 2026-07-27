class Solution {
public:
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=0;
        for (int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if (nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && visited[nr][nc]==1){
                dfs(nr,nc,grid,visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited=grid;
        for (int i=0;i<n;i++){
            if (grid[i][0]==1)dfs(i,0,grid,visited);
            if (grid[i][m-1]==1)dfs(i,m-1,grid,visited);
        }
        for (int i=0;i<m;i++){
            if (grid[0][i]==1)dfs(0,i,grid,visited);
            if (grid[n-1][i])dfs(n-1,i,grid,visited);
        }
        int ans=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (visited[i][j]==1)ans++;
            }
        }
        return ans;
    }
};