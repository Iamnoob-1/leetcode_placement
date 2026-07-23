class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool>&visited,int n){
        visited[node]=true;
        for (int i=0;i<n;i++){
            if (!visited[i] && isConnected[node][i]==1){
                dfs(i,isConnected,visited,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected.size();
        int ans=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if (!visited[i]){
                dfs(i,isConnected,visited,n);
                ans++;
            }
        }
        return ans;
    }
};