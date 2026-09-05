class DSU {
    vector<int> parent, rank;
public: 
    DSU(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    int findparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findparent(parent[node]);
    };
    void unionByRank(int u, int v){
        int u_par = findparent(u);
        int v_par = findparent(v);
        if(u_par == v_par) return;
        else if(rank[u_par] > rank[v_par]) parent[v_par] = u_par;
        else if(rank[v_par] > rank[u_par]) parent[u_par] = v_par;
        else {
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(dsu.findparent(u) == dsu.findparent(v)) return it;
            else{
                dsu.unionByRank(u, v);
            }
        }
        return {};
    }
};
