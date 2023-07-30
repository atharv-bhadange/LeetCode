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
public:
    bool tracePath(TreeNode* root, vector<TreeNode*>& path, TreeNode* find) {
        if(!root)
            return false;
        path.push_back(root);
        
        if(root == find)
            return true;
        
        if(root->left)
            if(tracePath(root->left, path, find))
                return true;
        if(root->right)
            if(tracePath(root->right, path, find))
                return true;
        
        path.pop_back();
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        
        tracePath(root, path1, p);
        tracePath(root, path2, q);
        
        int i=0;
        
        for(i=0; i<path1.size() && i<path2.size(); i++)
            if(path1[i] != path2[i])
                break;
        
        if(path1.size() < path2.size())
            return path1[i-1];
        else
            return path2[i-1];
        
    }
};