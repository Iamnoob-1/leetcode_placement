class Solution {
public:
    bool issafe(vector<vector<int>>&board,int row ,int col){
        int n=board.size();
        for (int i=0;i<row;i++)
            if (board[i][col]==1) return false;
         for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]) return false;
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j]) return false;

        return true;
    }
    void nqueens(vector<vector<int>>&board,int row,vector<vector<string>>&ans,int n,vector<string>subset){
        if (row==n) {
            for (int i = 0; i < n; i++) {
                string eachrow="";
                for (int j = 0; j < n; j++) {
                    eachrow+=(board[i][j]==1?'Q':'.');
                }
                subset.push_back(eachrow);
            }
            ans.push_back(subset);
            return;
        }
        for (int col=0;col<n;col++){
            if (issafe(board,row,col)){
                board[row][col]=1;
                nqueens(board,row+1,ans,n,subset);
                board[row][col]=0;
            }

        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
                vector<vector<int>> board(n, vector<int>(n, 0));
                vector<vector<string>>ans;
                vector<string>subset;
                nqueens(board,0,ans,n,subset);
                return ans;
        
    }
};