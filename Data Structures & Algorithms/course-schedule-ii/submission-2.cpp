class Solution {
public:
    vector<int> topo;
    bool iscycle(vector<vector<int>>& adj, int node, vector<int> &vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] == 1) return true;
            if(vis[it] == 0 && iscycle(adj, it, vis) == true) return true;
        }
        vis[node] = 2;
        topo.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }
        vector<int> vis(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            if(vis[i] == 0){
                if(iscycle(adj, i, vis) == true) return {};
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }
};
