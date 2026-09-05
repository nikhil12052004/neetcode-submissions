class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adj - {node, weight}
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        // pq - {dist, node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int nbr = it.first;
                int wt = it.second;
                if(dist[nbr] > wt + dis){
                    dist[nbr] = wt + dis;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1; i<dist.size(); i++){
            if(dist[i]==INT_MAX) return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};
