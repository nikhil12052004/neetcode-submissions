class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(auto &word : words){
            for(char ch : word){
                indegree[ch] = 0;
            }
        }

        for(int i = 0; i < n - 1; i++){
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.length(), s2.length());
            bool foundDiff = false;

            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    foundDiff = true;

                    if(adj[s1[j]].find(s2[j]) == adj[s1[j]].end()){
                        adj[s1[j]].insert(s2[j]);
                        indegree[s2[j]]++;
                    }

                    break;
                }
            }

            if(!foundDiff && s1.length() > s2.length()){
                return "";
            }
        }

        queue<char> q;

        for(auto it : indegree){
            if(it.second == 0) q.push(it.first);
        }

        string topo = "";

        while(!q.empty()){
            char node = q.front();
            q.pop();

            topo += node;

            for(char nbr : adj[node]){
                indegree[nbr]--;

                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        if(topo.size() != indegree.size()){
            return "";
        }

        return topo;
    }
};