class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=grid[0][0];
        queue<pair<int,int>>q;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        q.push({0,0});
        while (!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            // if (r==n-1 && c==m-1)return dist[r][c]<health;
            for (int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;
                if (dist[r][c]+grid[nr][nc]<dist[nr][nc]){
                    dist[nr][nc]=dist[r][c]+grid[nr][nc];
                    q.push({nr, nc});
                }
            }
        }
        return dist[n-1][m-1]<health;
    }
};