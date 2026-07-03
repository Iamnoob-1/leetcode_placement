class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int r=click[0];
        int c=click[1];
        if (board[r][c]=='M'){
            board[r][c]='X';
            return board;
        }

        queue<pair<int,int>>q;
        q.push({r,c});
        visited[r][c]=true;

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            int mine=0;
            for (int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if (nx>=0 && ny>=0 && nx<n && ny<m &&board[nx][ny]=='M'){
                    mine++;
                }
            }
            if (mine>0){
                board[x][y]=mine+'0';
            }
            else{
                board[x][y]='B';
                for (int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if (nx>=0 && ny>=0 && nx<n && ny<m &&!visited[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
            }
        }
        return board;
    }
};