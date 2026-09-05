class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto nbr : adj[node]){
            if(nbr == parent) continue;
            if(vis[nbr] == 1) return true;
            if(dfs(nbr, node, adj, vis) == true) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        if (dfs(0, -1, adj, vis)) return false;
        for(int i = 0; i<n; i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};
