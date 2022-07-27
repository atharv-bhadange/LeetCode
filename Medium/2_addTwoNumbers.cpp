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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *ans = new ListNode();
        ListNode *t = ans;
        int c = 0;
        while (p && q)
        {
            int now = p->val + q->val + c;
            c = now / 10;
            now %= 10;

            t->val = now;
            ListNode *temp = new ListNode();
            t->next = temp;
            t = t->next;
            p = p->next;
            q = q->next;
        }

        while (p)
        {
            int now = p->val + c;

            c = now / 10;

            now %= 10;

            t->val = now;

            ListNode *temp = new ListNode();
            t->next = temp;

            t = t->next;
            p = p->next;
        }

        while (q)
        {
            int now = q->val + c;

            c = now / 10;

            now %= 10;

            t->val = now;
            // t->val = q->val;

            ListNode *temp = new ListNode();

            t->next = temp;

            t = t->next;

            q = q->next;
        }
        cout << t->val << endl;
        cout << c << endl;
        t = ans;
        while (t->next->next)
        {
            t = t->next;
        }
        t->next = nullptr;

        if (c != 0)
        {
            ListNode *temp = new ListNode();
            temp->val = c;
            t->next = temp;
            t = t->next;
        }

        return ans;
    }
};