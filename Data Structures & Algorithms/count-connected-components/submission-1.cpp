class DSU{
    vector<int> rank, parent;
public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int u_par = findParent(u);
        int v_par = findParent(v);
        if(u_par == v_par) return;
        if(rank[u_par] > rank[v_par]){
            parent[v_par] = u_par;
        }
        else if(rank[v_par] > rank[u_par]){
            parent[u_par] = v_par;
        }
        else {
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }    
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto edge: edges){
            dsu.unionByRank(edge[0], edge[1]);
        }
        unordered_set<int> st;
        for(int i = 0; i<n; i++){
            st.insert(dsu.findParent(i));
        }
        return st.size();
    }
};
