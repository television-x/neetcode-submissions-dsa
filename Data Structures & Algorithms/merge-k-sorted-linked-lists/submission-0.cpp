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
    using _element = pair<int, ListNode*>;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<_element, std::vector<_element>, std::greater<_element>> _heap;

        int n = lists.size();

        for (int i = 0; i < n; ++i) {
            ListNode* curr = lists[i];
            while(curr){
                _heap.emplace(curr->val, curr);
                curr = curr->next;
            }
        }

        ListNode* _head = new ListNode(0);
        ListNode* dummy = _head;

        while(!_heap.empty()) {
            auto element = _heap.top();
            _heap.pop();

            dummy->next = element.second;
            dummy = dummy->next;

        }

        dummy->next = NULL;

        return _head->next;
    }
};
