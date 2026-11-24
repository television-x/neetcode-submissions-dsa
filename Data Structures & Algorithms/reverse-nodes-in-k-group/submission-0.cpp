/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {

private:
    ListNode* reverse_list(ListNode* head){
        if (!head || !head->next)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;


        vector<ListNode*> nodes;

        while(slow) {
            bool list_completed = false;
            ListNode* _head = slow;
            int n = 1;
            while(n < k){
                slow = slow->next;
                if (!slow){
                    list_completed = true;
                    break;
                }
                n+=1;
            }

            if (list_completed){
                nodes.push_back(_head);
                break;
            }

            ListNode* next_head = slow->next;
            slow->next = nullptr;


            nodes.push_back(reverse_list(_head));

            slow = next_head;
        }
        
        int nodes_len = nodes.size();
        
        for (int i = 0; i < nodes_len - 1; ++i) {
            ListNode* _tail = nodes[i];
            while(_tail->next)  _tail = _tail->next;
            _tail->next = nodes[i+1];
        }

        return nodes[0];
        
        
    }
};
