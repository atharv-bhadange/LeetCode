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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *t = head;
        int cnt = 1;
        ListNode *prev = nullptr;
        ListNode *nxt = nullptr;
        ListNode *curr = nullptr;

        while (t)
        {
            if (cnt == left)
            {
                nxt = t;
                curr = t;
            }
            if (cnt == 1 + right)
                prev = t;
            t = t->next;
            cnt++;
        }
        cnt = left;
        while (cnt != right + 1)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        t = head;
        if (left != 1)
        {
            cnt = 1;
            while (cnt != left - 1)
            {
                t = t->next;
                cnt++;
            }
            t->next = prev;
        }
        else
        {
            head = prev;
        }

        // return head;

        return head;
    }
};

// good question overall 
// same approach of 3 pointer