struct ListNode{
    int key;
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode() : key(0), val(0), next(NULL), prev(NULL) {}
    ListNode(int val1, int val2) : key(val1), val(val2), next(NULL), prev(NULL) {}
};

class LRUCache {
private:
    void addFront(ListNode* node){
        ListNode* head_next = head->next;
        head->next = node;
        node->next = head_next;
        node->prev = head;
        head_next->prev = node;

        // map addition remaining        
    }

    void remove(ListNode* node){
        ListNode* previous = node->prev;
        ListNode* nextt = node->next;
        previous->next = nextt;
        nextt->prev = previous;
    }

public:
    int _capacity;
    unordered_map<int, ListNode*> mapping; // key -> pointer of list

    ListNode* head;
    ListNode* tail;

    LRUCache(int capacity) {
        _capacity = capacity;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mapping.find(key) == mapping.end())
            return -1;
        
        ListNode* lru = mapping[key];
        remove(lru);
        addFront(lru);

        return lru->val;
    }
    
    void put(int key, int value) {
        ListNode* node;

        if (mapping.find(key) == mapping.end()){
            node = new ListNode(key, value);
            if (mapping.size() == _capacity){
                ListNode* lru = tail->prev;
                remove(lru);
                mapping.erase(lru->key);
                delete lru;  
            }
            addFront(node);
            mapping[key] = node;
        }else{
            node = mapping[key];
            node->val = value;
            remove(node);
            mapping.erase(key);
            addFront(node);
            mapping[key] = node;
        }
    }
};

/*


values = key, val

map key and the pointer address;

map size == cap -> remove from the tail and add the new to the front;

already in map remove from the list and add it in the front

else map < cap then directly addin front


*/


