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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = new ListNode(), *h2 = new ListNode();
        ListNode* p = head, *q = h1, *r = h2;
        while(p) {
            ListNode* t = new ListNode();
            t->val = p->val;
            if(p->val < x) {
                q->next = t;
                q = q->next;
            }
            else {
                r->next = t;
                r = r->next;
            }
            p = p->next;
        }
        
        q->next = h2->next;
        
        return h1->next;
    }
};