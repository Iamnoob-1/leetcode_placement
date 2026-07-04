class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if (q.empty()||q.size()==n*m)return -1;
        int distance=-1;
        while (!q.empty()){
            int qsize=q.size();
            while (qsize--){
                auto[r,c]=q.front();
                q.pop();
                for (int i=0;i<4;i++){
                    int nr=r+dx[i];
                    int nc=c+dy[i];
                    if (nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};