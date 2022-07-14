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
    void rightView(TreeNode *p, int level, vector<int> &ans)
    {
        if (p == nullptr)
            return;
        if (level == ans.size()) // will execute first time only i.e. when called upon rightmost child
            ans.push_back(p->val);

        rightView(p->right, level + 1, ans);
        rightView(p->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        rightView(root, 0, ans);
        return ans;
    }
};

// reverse preorder travesal
// visit->right->left