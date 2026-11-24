/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;

        unordered_map<Node*, Node*> _map;

        Node* new_head = new Node(0);
        Node* _head = new_head;

        Node* curr = head;


        while(curr) {
            Node* new_node = new Node(curr->val);

            new_head->next = new_node;

            new_head = new_node;

            _map[curr] = new_node;

            curr = curr->next;
            
        }

        curr = head;
        new_head = _head->next;

        while(curr && new_head) {

            Node* connect = _map[curr->random];
            new_head->random = connect;

            curr = curr->next;
            new_head = new_head->next;
        }

        return _head->next;
    }
};
