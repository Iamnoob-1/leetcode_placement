class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int v=quiet.size();
        vector<int>indegree(v);
        vector<int>ans(v);
        for (int i=0;i<v;i++){
            ans[i]=i;
        }
        vector<vector<int>>adj(v);
        for (auto it:richer){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for (int i=0;i<v;i++){
            if (indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for (auto it:adj[u]){
                if (quiet[ans[u]] < quiet[ans[it]])
                    ans[it] = ans[u];
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return ans;
    }
};