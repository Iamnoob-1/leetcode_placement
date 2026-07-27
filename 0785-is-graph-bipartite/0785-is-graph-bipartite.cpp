class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>color(n,-1);
        queue<int>q;
        for (int i=0;i<n;i++){
            if (color[i]!=-1)continue;

            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for (int node:graph[curr]){
                    if (color[node]==-1){
                        color[node]=!color[curr];
                        q.push(node);
                    }
                    if (color[node]==color[curr])return false;
                }
            }
        }
        return true;
    }
};