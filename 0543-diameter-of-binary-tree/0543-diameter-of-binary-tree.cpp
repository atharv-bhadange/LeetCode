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
    int height(TreeNode* root, int& d) {
        if(!root) {
            return 0;
        }
        int l = height(root->left, d);
        int r = height(root->right, d);
            
        d = max(l+r, d);
        
        return max(l,r)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        
        return ans;
    }
};