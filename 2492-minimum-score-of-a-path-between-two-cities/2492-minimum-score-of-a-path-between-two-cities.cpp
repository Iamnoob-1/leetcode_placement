class Solution {
public:

int ans=INT_MAX;
    void dfs(int node,vector<bool>&vis,vector<vector<pair<int,int>>>&adj){
        vis[node]=true;
        for (auto&it:adj[node]){
            int next=it.first;
            int wt=it.second;
            ans=min(ans,wt);
            if (!vis[next]){
                dfs(next,vis,adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool>vis(n+1,false);
        vector<vector<pair<int,int>>>adj(n+1);
        for (auto & it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1,vis,adj);
        return ans;
    }
};