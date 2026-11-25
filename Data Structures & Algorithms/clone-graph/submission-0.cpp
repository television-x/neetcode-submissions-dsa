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
    unordered_map<Node*, bool> visited_original;
    unordered_map<Node*, bool> visited;

    unordered_map<Node*, Node*> mapping; // original, copy corresponding

    void create_graph_connections(Node* node){
        if (visited[node])
            return;
        
        visited[node] = true;

        Node* root = mapping[node];

        for (auto x : node->neighbors){
            root->neighbors.push_back(mapping[x]);
            create_graph_connections(x);
        }
    }

    void create_graph_nodes(Node * node) {
        if (visited_original.count(node))
            return;
        
        Node * root = new Node(node->val);
        visited_original[node] = true;

        mapping[node] = root;

        for (auto x : node->neighbors){
            create_graph_nodes(x);
        }
    }

    Node* cloneGraph(Node* node) {

        if (node == NULL)
            return node;

        create_graph_nodes(node);

        create_graph_connections(node);

        return mapping[node];

    }
};



/*

approach -> 
node create a node while and then go to its neighbours and then create a node and so on

recursive function  **



*/