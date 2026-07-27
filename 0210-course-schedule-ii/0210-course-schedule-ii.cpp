class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adj(V);
        for (auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(V,0);
        for (int i=0;i<V;i++){
            for(int it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for (int i=0;i<V;i++){
            if (indegree[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for (int it:adj[node]){
                indegree[it]--;
                if (indegree[it]==0)q.push(it);
            }
        }
        return count==V?ans:vector<int>{};
    }
};