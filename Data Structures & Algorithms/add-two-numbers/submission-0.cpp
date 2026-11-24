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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        bool check = false;

        ListNode* _head = new ListNode(0);
        ListNode* dummy = _head;

        while(l1 && l2) {
            int value = l1->val + l2->val;
            
            if (check){
                value += carry;
                carry = 0;
                check = false;
            }

            if (value >= 10){
                value = value%10;
                carry = 1;
                check = true;
            }

            ListNode* new_node = new ListNode(value);

            dummy->next = new_node;
            dummy = new_node; 

            l1 = l1->next;
            l2 = l2->next;
            
        }
        
        while (l1){
             
            if (check){
                l1->val += carry;
                carry = 0;
                check = false;
                if (l1->val >= 10){
                    carry = 1;
                    l1->val %= 10;
                    check = true;
                }
            }

            dummy->next = l1;
            dummy = dummy->next;
            l1 = l1->next;


        }
        while (l2){
            if (check){
                l2->val += carry;
                carry = 0;
                check = false;
                if (l2->val >= 10){
                    carry = 1;
                    l2->val %= 10;
                    check = true;
                }
            }

            dummy->next = l2;
            dummy = dummy->next;
            l2 = l2->next;
        }

        if (check) {
            dummy->next = new ListNode(carry);
        }

        // _head = reverse_list(_head->next);

        return _head->next;
    }
};
