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
class Solution
{
public:
    set<TreeNode *> s;
    int ans;

    void dfs(TreeNode *c, TreeNode *p)
    {
        if (c != nullptr)
        {
            dfs(c->left, c);
            dfs(c->right, c);
            if ((p == nullptr && s.find(c) == s.end()) || s.find(c->left) == s.end() || s.find(c->right) == s.end())
            {
                ans++;
                s.insert(p);
                s.insert(c);
                s.insert(c->left);
                s.insert(c->right);
            }
        }
    }

    int minCameraCover(TreeNode *root)
    {
        s.insert(nullptr);
        ans = 0;
        dfs(root, nullptr);
        return ans;
    }
};

// applying dfs to tree
// in two cases only will the nodes be unwatched
// 1. when current node's child is unwatched
// 2. when current node's parent is null
// basically we start to place camera from leaf node