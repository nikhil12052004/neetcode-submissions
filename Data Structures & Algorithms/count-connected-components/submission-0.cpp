class Solution {
public:
    int cnt = 0;
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        for(auto it : adj[node]){
            if(vis[it] != 1){
                vis[it] = 1;
                dfs(it, vis, adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                cnt++;
                vis[i] = 1;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};
