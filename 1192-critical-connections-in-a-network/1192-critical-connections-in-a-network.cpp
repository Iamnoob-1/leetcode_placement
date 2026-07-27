class Solution {
public:
    vector<vector<int>>bridges;
    vector<int>tin;
    vector<int>low;
    int time=0;
    void dfs(int node,int parent,vector<int>&visited,vector<vector<int>>&adj){
        visited[node]=1;
        tin[node]=low[node]=time++;
        for(auto it:adj[node]){
            if (it==parent)continue;
            if (visited[it]==0){
                dfs(it,node,visited,adj);
                low[node]=min(low[node],low[it]);

                if (low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        } 
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for (auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        tin.resize(n);
        low.resize(n);
        vector<int>visited(n,0);
        dfs(0,-1,visited,adj);
        return bridges;
        
    }
};