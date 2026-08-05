class Solution {
public:
unordered_set<int>st;
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;
        for (auto it:adj[node]){
            if(!visited[it]){
                st.insert(it);
                dfs(it,adj,visited);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for (auto it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>visited(n,false);
        st.insert(k);
        dfs(k,adj,visited);
         for (auto it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!visited[u] && visited[v]) {
                vector<int> ans;
                for (int i =0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                ans.push_back(i);
        }
        return ans;
        // for (auto it:st){
        //     cout<<it;
        // }
        // return {};
        vector<bool>suspicious=visited;
        // for (int i=0;i<n;i++){
        //     if (!suspicious[i]){
        //         dfs2(i,adj,suspicious);
        //     }
        // }
        // for (int i=0;i<visited.size();i++){
        //     cout<<suspicious[i];
        // }
        return {};


    }
};