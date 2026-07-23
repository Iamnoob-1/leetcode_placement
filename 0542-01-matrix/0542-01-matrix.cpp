class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        // vector<vector<int>>dist
        queue<pair<int,int>>q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        while (!q.empty()){
            int qsize=q.size();
            for (int i=0;i<qsize;i++){
                auto[x,y]=q.front();
                q.pop();
                for (int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if (nx>=0 && nx<n && ny>=0 && ny<m &&mat[nx][ny]==-1){
                        q.push({nx,ny});
                        mat[nx][ny]=mat[x][y]+1;
                    }
                }
            }
        }
        return mat;
    }
};