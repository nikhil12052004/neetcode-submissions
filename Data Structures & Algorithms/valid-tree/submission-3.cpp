class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis){
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                if(dfs(it, node, adj, vis)) return true;;
            }
            else if(parent != it){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                vis[i] = 1;
                if(dfs(i, -1, adj, vis) == true) return false;
            }
        }
        for(int i = 0; i<n; i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};
