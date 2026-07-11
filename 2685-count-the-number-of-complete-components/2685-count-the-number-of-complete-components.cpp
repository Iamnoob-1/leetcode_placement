class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for (auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        int ans=0;
        for (int i=0;i<n;i++){

            if (visited[i])continue;

            vector<int> component;
            queue<int>q;
            q.push(i);
            visited[i]=true;
            while (!q.empty()){
                int node=q.front();
                q.pop();
                component.push_back(node);
                for (int nbr:adj[node]){
                    if (!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
        
            int size = component.size();
            bool complete = true;

            for (int node : component) {
                if (adj[node].size() != size-1) {
                    complete = false;
                    break;
                }
            }

            if (complete)
                ans++;
            
        }
        return ans;
    }
};