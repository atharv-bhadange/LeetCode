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
    int curr = 0;
    int str = 0;
    int mxStr = 0;
    vector<int> ans;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            
            if(root->val == curr) {
                str++;
            } else {
                str = 1;
                curr = root->val;
            }
            
            if(str > mxStr) {
                ans = {};
                mxStr = str;
            }
            if(str == mxStr) {
                ans.push_back(root->val);
            }
            
            inorder(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};