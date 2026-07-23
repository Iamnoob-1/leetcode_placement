class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        int m=isConnected[0].size();
        queue<int>q;
        vector<bool>visited(n,false);
        for (int i=0;i<n;i++){
            if (!visited[i]){
                ans++;
                q.push(i);
                while (!q.empty()){
                    int curr=q.front();
                    q.pop();
                    for (int j=0;j<n;j++){
                        if (!visited[j] && isConnected[curr][j]==1){
                            q.push(j);
                            visited[j]=true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};