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
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *p = head;
        ListNode *ans = new ListNode();
        ListNode *q = ans;
        while (p)
        {
            if (p->val < x)
            {
                q->val = p->val;
                ListNode *t = new ListNode();
                // if(p->next){
                q->next = t;
                q = q->next;
                // }
            }
            p = p->next;
        }
        p = head;
        while (p)
        {
            if (p->val >= x)
            {
                q->val = p->val;
                ListNode *t = new ListNode();
                // if(p->next){
                q->next = t;
                q = q->next;
                // }
            }
            p = p->next;
        }
        p = ans;
        while (p->next->next)
        {
            p = p->next;
        }
        cout << p->val << " ";
        p->next = nullptr;
        return ans;
    }
};

// create a new list