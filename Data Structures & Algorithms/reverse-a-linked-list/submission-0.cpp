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
    using _ln = ListNode*;
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        _ln curr = head->next;
        _ln prev = head;


        head->next = nullptr;

        while(curr != nullptr) {
            _ln _next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = _next;
        }

        return prev;


    }
};
