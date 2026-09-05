/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mpp;
    void dfs(Node* node, Node* node_clone){
        for(auto n : node->neighbors){
            if(mpp.find(n) == mpp.end()){
                Node* n_clone = new Node(n->val);
                node_clone->neighbors.push_back(n_clone);
                mpp[n] = n_clone;
                dfs(n, n_clone);
            }
            else{
                node_clone->neighbors.push_back(mpp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* node_clone = new Node(node->val);
        mpp[node] = node_clone;
        dfs(node, node_clone);
        return node_clone;
    }
};
