class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)return image;
        int ans=0;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        int original=image[sr][sc];
        q.push({sr,sc});
        image[sr][sc]=color;
        while (!q.empty()){
            int qsize=q.size();
            for (int i=0;i<qsize;i++){
                auto[x,y]=q.front();
                q.pop();
                for (int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if (nx>=0 && nx<n && ny>=0 && ny<m &&image[nx][ny]==original){
                        q.push({nx,ny});
                        image[nx][ny]=color;
                    }
                }
            }
        }
        return image;
    }
};