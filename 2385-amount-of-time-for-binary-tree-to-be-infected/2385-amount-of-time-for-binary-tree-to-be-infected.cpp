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
    void inorder(TreeNode* root, unordered_map<int, vector<int>>& graph) {
        if(!root)
            return;
        inorder(root->left, graph);
        if(root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        } 
        if(root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        inorder(root->right, graph);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        
        inorder(root, graph);
        
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        int ans = -1;
    
        while (!q.empty()) {
            ans++;
            for (int levelSize = q.size(); levelSize > 0; --levelSize) {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                for (int adjacentNode : graph[currentNode]) {
                    if (!visited.count(adjacentNode)) {
                        q.push(adjacentNode);
                    }
                }
            }
        }
        
        return ans;
    }
};