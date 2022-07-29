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
    vector<TreeNode *> v;

    void preorder(TreeNode *p)
    {
        if (p)
        {
            v.push_back(p);
            preorder(p->left);
            preorder(p->right);
        }
    }

    void flatten(TreeNode *root)
    {
        if (root)
        {
            preorder(root);
            int i = 0;
            for (i = 0; i < v.size() - 1; i++)
            {
                cout << v[i]->val << " ";
                v[i]->right = v[i + 1];
                v[i]->left = nullptr;
            }
            v[v.size() - 1]->right = nullptr;
            v[v.size() - 1]->left = nullptr;

            root = v[0];
        }
    }
};

// recursive preorder and storing it in vector
// joining consecutive elements to right 