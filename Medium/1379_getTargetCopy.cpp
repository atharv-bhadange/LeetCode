/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans = nullptr;
public:
//     void preorder(TreeNode* temp, TreeNode* temp1, TreeNode* target)
//     {
//         if(temp==nullptr || temp==nullptr) return;
        
//         if(temp==target) ans = 
        
//     }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        TreeNode* p = original;
        TreeNode* p1 = cloned;
        stack<TreeNode *> st,st2;
    while(p || !st.empty() || p1 || !st2.empty())
    {
        if(p || p1)
        {
            if(p==target)
            {
                ans = p1;
                break;
            }
            st.push(p);
            st2.push(p1);
            p=p->left;
            p1=p1->left;
        }
        else
        {
            p=st.top();
            p1=st2.top();
            st.pop();
            st2.pop();
            p=p->right;
            p1=p1->right;
        }
    }
        return ans;
    }
};

// Tried to use recursive preorder function but it was not working.
// Easier to use stack.
