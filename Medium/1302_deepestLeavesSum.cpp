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
    int ans = 0;
    
    int h=0;
public:
    int height(TreeNode* temp)
    {
        if(!temp) return 0;
        int l = height(temp->left);
        int r = height(temp->right);
        if(l>r) return l+1;
        return r+1;
    }
    int preorder(TreeNode *temp, int level)
    {
        if(!temp)
            return 0;
        if(!temp->left && !temp->right && level==h)
        {
            ans+=temp->val;
        }
        int l = preorder(temp->left, level+1);
        if(l) return l;
        
        int r = preorder(temp->right,level+1);
        return r;
    }
    int deepestLeavesSum(TreeNode* root) {
        h = height(root);
        preorder(root,1);
        return ans;
    }
};