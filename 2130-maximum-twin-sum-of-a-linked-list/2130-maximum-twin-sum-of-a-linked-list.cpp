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
    int pairSum(ListNode* head) {
        stack<int> st;
        
        ListNode* p = head;
        
        while(p) {
            st.push(p->val);
            p = p->next;
        }
        
        int sz = st.size();
        int ans = 0;
        sz/=2;
        p = head;
        while(sz--) {
            ans = max(ans, p->val + st.top());
            st.pop();
            p = p->next;
        }
        
        return ans;
    }
};