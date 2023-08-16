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
    void maxZigZag(TreeNode* node, int dir, int steps) {
        if(!node) 
            return;
        ans = max(ans, steps);
        if(dir<0) {
            maxZigZag(node->right, 1, steps+1);
            maxZigZag(node->left, -1, 1);
        }
        else {
            maxZigZag(node->left, -1, steps+1);
            maxZigZag(node->right, 1, 1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        maxZigZag(root, 1, 0);
        
        return ans;
    }
};