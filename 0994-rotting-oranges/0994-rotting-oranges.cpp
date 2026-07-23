class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int rotten=0;
        int normal=0;
        queue<pair<int,int>>q;
        vector<vector<int>>visited=grid;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1)normal++;
                if (grid[i][j]==2){
                    rotten++;
                    q.push({i,j});
                }
            }
        }
        if (normal==0)return 0;
        if (rotten==0)return -1;
        int time=0;
        while (!q.empty()){
            int qsize=q.size();
            for (int i=0;i<qsize;i++){
                auto [x,y]=q.front();
                q.pop();
                for (int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if (nx>=0 && nx<n && ny >=0 && ny<m &&visited[nx][ny]==1){
                        visited[nx][ny]=2;
                        normal--;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        
        return normal>0?-1:time-1;

    }
};