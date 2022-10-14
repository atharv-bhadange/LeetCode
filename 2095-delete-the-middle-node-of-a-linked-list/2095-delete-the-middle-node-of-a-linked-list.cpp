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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)
        {
            delete head;
            return nullptr;
        }
        ListNode* slow = head, *fast = head, *follow = nullptr;
        // cout<<0;
        while(fast!=nullptr && fast->next!=nullptr) {
            follow = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }
        // cout<<1;
        if(follow){
            follow->next = slow->next;
            delete slow;
            slow = nullptr;
        }
        
        return head;
    }
};