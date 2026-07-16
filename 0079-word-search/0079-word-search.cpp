class Solution {
public:
    bool recursion(vector<vector<char>>&board,string word,int i,int j,int index,vector<vector<bool>>&visited){
        if (index==word.size())return true;
        if (i<0 || i>=board.size()||j<0 ||j>=board[0].size())return false;
        if (visited[i][j])return false;
        if (board[i][j]!=word[index])return false;

        visited[i][j]=true;
        bool found=recursion(board, word, i + 1, j, index + 1, visited) ||
            recursion(board, word, i - 1, j, index + 1, visited) ||
            recursion(board, word, i, j + 1, index + 1, visited) ||
            recursion(board, word, i, j - 1, index + 1, visited);
        visited[i][j]=false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word=="")return false;

        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j]==word[0]){
                    if(recursion(board,word,i,j,0,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};