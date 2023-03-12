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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0; i<lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp)
            {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        if(pq.empty())
            return nullptr;
        ListNode* ans = new ListNode(pq.top());
        pq.pop();
        ListNode* p = ans;
        while(!pq.empty())
        {
            ListNode* temp = new ListNode(pq.top());
            pq.pop();
            p->next = temp;
            p = p->next;
        }
        
        return ans;
    }
};