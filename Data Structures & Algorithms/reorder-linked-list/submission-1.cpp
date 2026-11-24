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
public:

    ListNode* reverse_list(ListNode* head){
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;

        fast = reverse_list(fast);

        ListNode* dummy = head;

        bool turn = true;

        while(dummy && fast) {
            
            ListNode* temp = dummy->next;
            ListNode* _temp = fast->next;

            dummy->next = fast;
            fast->next = temp;
            
            // temp->next = _temp;

            fast = _temp;
            dummy = temp;
        }

        
    }
};
