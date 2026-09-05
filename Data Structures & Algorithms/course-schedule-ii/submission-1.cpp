class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }
        vector<int> topo;
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        for(auto it : adj){
            for(int i = 0; i<it.size(); i++){
                indegree[it[i]]++;
            }
        }
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() != numCourses) return {};
        return topo;   
    }
};
