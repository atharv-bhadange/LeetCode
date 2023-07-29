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
    void preor(TreeNode* root, set<int>& st) {
        if(root) {
            st.insert(root->val);
            preor(root->left, st);
            preor(root->right, st);
        }
    } 
    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        preor(root, st);
        
        if(st.size() <= 1)
            return -1;
        auto it = st.begin();
        return *(++it);
    }
};