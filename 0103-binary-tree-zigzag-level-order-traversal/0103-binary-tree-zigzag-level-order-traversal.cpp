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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;

        bool toRight = true;
        q.push(root);        
        while(!q.empty()) {
            int cur_size = q.size();
            vector<int> temp(cur_size);
            
            for(int i=0; i<cur_size; i++) {
                auto node = q.front();
                q.pop();
                
                int idx = toRight ? i : cur_size-1-i;
                
                temp[idx] = node->val;
                
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            
            toRight = !toRight;
            ans.push_back(temp);
        }
        
        return ans;
    }
};