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
    unordered_map<int,int> mp;
    int height(TreeNode* root, int h) {
        int r=0,l=0;
        if(root) {
            l = height(root->left, h+1);
            r = height(root->right, h+1);
            mp[h]+=root->val;
        } else 
            return 0;
        
        return max(r,l) + 1;
    }
    
    int maxLevelSum(TreeNode* root) {
        height(root, 1);
        int ans = 0, maxi = INT_MIN;
        for(auto& it: mp) {
            if(it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            }
        }
        
        return ans;
    }
};