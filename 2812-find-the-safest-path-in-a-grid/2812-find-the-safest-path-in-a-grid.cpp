class Solution {
public:
    
    int n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    bool canreach(vector<vector<int>>& dist, int limit) {

        int n = dist.size();

        if (dist[0][0] < limit)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc] &&
                    dist[nr][nc] >= limit) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,-1));
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for (int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if (nr>=0 && nr<n && nc>=0 && nc<n &&dist[nr][nc]==INT_MAX ){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        int low=0;
        int high =2*n;
        int ans=0;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (canreach(dist,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};