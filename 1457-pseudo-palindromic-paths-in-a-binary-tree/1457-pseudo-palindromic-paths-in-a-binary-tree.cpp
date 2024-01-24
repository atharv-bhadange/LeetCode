/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void recur(TreeNode* p, unordered_map<int,int>& m)
    {
        if(!p) return;
        m[p->val]++;
        if(!p->left && !p->right)
        {
            int odd = 0;
            for(auto&x : m)
            {
                if(x.second%2!=0)
                    odd++;
            }
            if(odd>1){
                m[p->val]--;
                return;
            }
            else
                ans++;
        }
        
        recur(p->left,m);
        recur(p->right,m);
        m[p->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> m;
        recur(root,m);
        
        return ans;
    }
};