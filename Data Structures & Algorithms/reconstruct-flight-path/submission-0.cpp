class Solution {
public:
    vector<string> ans;
    unordered_map<string, vector<string>> adj;
    int totaltickets = 0;

    bool dfs(string fromairport, vector<string> &path){
        path.push_back(fromairport);

        if(path.size() == totaltickets + 1){
            ans = path;
            return true;
        }

        vector<string> &nbrs = adj[fromairport];
        for(int i = 0; i<nbrs.size(); i++){
            string toairport = nbrs[i];

            // removing ticket 
            nbrs.erase(nbrs.begin() + i);

            if(dfs(toairport, path) == true) return true;

            //adding ticket
            nbrs.insert(nbrs.begin() + i, toairport);
        }
        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        totaltickets = tickets.size();
        for(auto &e : tickets){
            string u = e[0];
            string v = e[1];
            adj[u].push_back(v);
        }
        //lexical order
        for(auto &it : adj){
            sort(it.second.begin(), it.second.end());
        }

        vector<string> path;
        dfs("JFK", path);

        return ans;
    }
};
